#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "time.h"

/* Декларування структури для комірок */
struct bucket {
    int count; // лічильник елементів
    double* values; // Вказівник на елемент масиву
};

/* Прототипи функцій */
int element_counter(FILE*& fd);
int workWithArray(double* array, int counter, int type_of_sorting);
void sortInsert(double* arr, int n, clock_t start_t, clock_t end_t, long double* total_t);
void mergeSort(double* array, int left, int right, clock_t start_t, clock_t end_t, long double* total_t);
void merge(double* arr, int l, int m, int r);
int compareIntegers(const void* first, const void* second);
int bucketSort(double* array, int n, clock_t start_t, clock_t end_t, long double* total_t);


int main(int argc, char* argv[]) {
    FILE* fr = NULL; //файловий дескриптор для встановлення потоку з файлом
    FILE* fr2 = NULL; //файловий дескриптор для встановлення потоку з файлом
    double* array = NULL; //покажчик на масив для зберігання даних
    double* temp_array = NULL; //покажчик на додатковий масив для зберігання даних
    int sortingType = 0, //змінна пункту меню, яка відповідає за вибір типу сортування
        fillingType = 0, //змінна пункту меню, яка відповідає за вибір типу заповнення масиву
        minimum, //змінна для зберігання значення лівої границі для генерації випадкових чисел
        maximum, //змінна для зберігання значення правої границі для генерації випадкових чисел
        counter = 0; //розмір масиву
    char filename[256]; //рядок з назвою першого файлу
    char filename2[256]; //рядок з назвою другого файлу

    SetConsoleCP(1251); //підключення кирилиці
    SetConsoleOutputCP(1251);

    srand(time(NULL)); //встановлює поточний час як базу для функції "rand()"

    printf("Виберіть тип сортування:\n1)Сортування вставкою;\n2)Сортування злиттям;\n3)Сортування комірками.\n4)Завершити програму;\n");
    scanf_s("%d", &sortingType);

    if (sortingType < 1 || sortingType > 4) {
        printf("Ви ввели некоректне значення!\n");
        return 1;
    }

    if (sortingType == 4) {
        printf("Робота програми завершена!\n");
        return 0;
    }


    printf("Oберіть те, як ви бажаєте працювати з масивом:\n1)ввести дані для нього з файлу;\n2)заповнити файл випадковими числами і зчитати їх звідти;\n3)тестовий режим(заповнення файлу з клавіатури в консоль).\n");
    scanf_s("%d%*c", &fillingType);

    if (fillingType < 1 || fillingType > 3) {
        printf("Ви ввели некоректне значення!\n");
        return 1;
    }

    switch (fillingType) {
    case 1: {
        printf("Введіть назву файлу у вигляді name.txt, з якого бажаєте зчитати дані для масиву:\n");
        fgets(filename, 1024, stdin);
        filename[strlen(filename) - 1] = '\0';

        if ((fr = fopen(filename, "r")) == NULL) //вiдкриття файлу, та перевірка на помилки
        {
            printf("Виникла помилка при відкритті файлу %s! \n", filename);
            return 1;
        }

        printf("Введіть назву файлу у вигляді name.txt, до якого бажаєте переписати відсортований масив:\n");
        fgets(filename2, 1024, stdin);
        filename2[strlen(filename2) - 1] = '\0';

        if ((fr2 = fopen(filename2, "w")) == NULL) //вiдкриття файлу, та перевірка на помилки
        {
            printf("Виникла помилка при відкритті файлу %s! \n", filename2);
            return 1;
        }

        counter = element_counter(fr);
        array = (double*)malloc(counter * sizeof(double));

        for (int i = 0; i < counter; i++) { //зчитування даних з файлу і запису їх до комірок масиву
            fscanf(fr, "%lf", &array[i]);
        }

        fclose(fr); //закриття файлу

        if (ferror(fr)) { //перевірка закриття файлу на помилки
            printf("Помилка при закритті файлу %s", filename);
            return 1;
        }
        break;
    }
    case 2: {
        printf("Введіть назву файлу у вигляді name.txt, з якого після заповнення бажаєте зчитати дані для масиву:\n");
        fgets(filename, 1024, stdin);
        filename[strlen(filename) - 1] = '\0';

        if ((fr = fopen(filename, "w")) == NULL) //вiдкриття файлу, та перевірка на помилки
        {
            printf("Виникла помилка при відкритті файлу %s! \n", filename);
            return 1;
        }

        printf("Введіть назву файлу у вигляді name.txt, до якого бажаєте переписати відсортований масив:\n");
        fgets(filename2, 1024, stdin);
        filename2[strlen(filename2) - 1] = '\0';

        if ((fr2 = fopen(filename2, "w")) == NULL) //вiдкриття файлу, та перевірка на помилки
        {
            printf("Виникла помилка при відкритті файлу %s! \n", filename2);
            return 1;
        }

        printf("Введіть кількість елементів масиву:\n");
        scanf_s("%d", &counter);

        if (counter < 1) {
            printf("Введене некоректне значення!");
            return 1;
        }

        array = (double*)malloc(counter * sizeof(double));
        temp_array = (double*)malloc(counter * sizeof(double));

        do {
            printf("Введіть нижню границю для генерації випадкових чисел:\n");
            scanf("%d", &minimum);

            printf("Введіть верхню границю для генерації випадкових чисел:\n");
            scanf("%d", &maximum);

            if (maximum < minimum) {
                printf("Верхня границя не може бути меншою за нижню!\n");
                return 1;
            }
        } while (maximum < minimum);

        for (int i = 0; i < counter; i++) {
            temp_array[i] = minimum + rand() % (maximum - minimum + 1);
        }

        for (int i = 0; i < counter; i++) {
            if (!fprintf(fr, "%lf\n", temp_array[i]))
            {
                printf("Помилка при закритті файлу %s!\n", filename);
                return 1;
            }
        }

        fclose(fr); //закриття файлу

        if (ferror(fr)) { //перевірка закриття файлу на помилки
            printf("Помилка при закритті файлу %s", filename);
            return 1;
        }

        free(temp_array); //звільняємо пам'ять динамічного масиву

        if ((fr = fopen(filename, "r")) == NULL) //вiдкриття файлу, та перевірка на помилки
        {
            printf("Виникла помилка при відкритті файлу %s! \n", filename);
            return 1;
        }

        for (int i = 0; i < counter; i++) { //зчитування даних з файлу і запису їх до комірок масиву
            fscanf(fr, "%lf", &array[i]);
        }

        fclose(fr);

        if (ferror(fr)) { //перевірка закриття файлу на помилки
            printf("Помилка при закритті файлу %s", filename);
            return 1;
        }

        break;
    }
    case 3: {
        printf("Введіть назву файлу у вигляді name.txt, з якого після заповнення бажаєте зчитати дані для масиву:\n");
        fgets(filename, 1024, stdin);
        filename[strlen(filename) - 1] = '\0';

        if ((fr = fopen(filename, "w")) == NULL) //вiдкриття файлу, та перевірка на помилки
        {
            printf("Виникла помилка при відкритті файлу %s! \n", filename);
            return 1;
        }

        printf("Введіть назву файлу у вигляді name.txt, до якого бажаєте переписати відсортований масив:\n");
        fgets(filename2, 1024, stdin);
        filename2[strlen(filename2) - 1] = '\0';

        if ((fr2 = fopen(filename2, "w")) == NULL) //вiдкриття файлу, та перевірка на помилки
        {
            printf("Виникла помилка при відкритті файлу %s! \n", filename2);
            return 1;
        }

        printf("Введіть кількість елементів масиву:\n");
        scanf_s("%d", &counter);

        if (counter < 1) {
            printf("Введене некоректне значення!");
            return 1;
        }

        array = (double*)malloc(counter * sizeof(double));
        temp_array = (double*)malloc(counter * sizeof(double));

        for (int i = 0; i < counter; i++) {
            printf("Введіть елемент [%d] масиву:\n", i + 1);
            scanf("%lf", &temp_array[i]);
        }

        for (int i = 0; i < counter; i++) {
            if (!fprintf(fr, "%lf\n", temp_array[i]))
            {
                printf("Помилка при закритті файлу %s!\n", filename);
                return 1;
            }
        }

        free(temp_array); //звільняємо пам'ять динамічного масиву

        fclose(fr); //закриття файлу

        if (ferror(fr)) { //перевірка закриття файлу на помилки
            printf("Помилка при закритті файлу %s", filename);
            return 1;
        }

        if ((fr = fopen(filename, "r")) == NULL) //вiдкриття файлу, та перевірка на помилки
        {
            printf("Виникла помилка при відкритті файлу %s! \n", filename);
            return 1;
        }

        for (int i = 0; i < counter; i++) { //зчитування даних з файлу і запису їх до комірок масиву
            fscanf(fr, "%lf", &array[i]);
        }

        fclose(fr); //закриття файлу

        if (ferror(fr)) { //перевірка закриття файлу на помилки
            printf("Помилка при закритті файлу %s", filename);
            return 1;
        }

        break;
    }
    }


        workWithArray(array, counter, sortingType); // сортування даних

        for (int i = 0; i < counter; i++) {
            if (!fprintf(fr2, "%lf\n", array[i]))
            {
                printf("Помилка при записуванні масиву у файл!\n");
                return 1;
            }
        }

        free(array); //звільняємо пам'ять динамічного масиву

        fclose(fr2); //закриття файлу

        if (ferror(fr2)) { //перевірка закриття файлу на помилки
            printf("Помилка при закритті файлу %s", filename2);
            return 1;
        }
    
}

/*Функція для підрахунку кількості елементів у файлі
Вхід:
Файловий дескриптор fd
Значення, що повертається функцією:
Кількість елементів у файлі count*/
int element_counter(FILE*& fd) {
    int count = 0; //змінна для підрахунку кількості елементів, що зберігається у файлі

    while (!feof(fd)) { //поки не дійшли до кінця файлу
        fscanf(fd, "%*lf\n");
        count++;
    }
    rewind(fd); //переміщує показник в початок файлу
    if (ferror(fd)) {
        printf("Не переміщено показник в початок файлу\n");
        exit(0);
    }
    return count;
}

/*Функція для надсилання даних з масиву на сортування, яке обрав користувач
Вхід:
Вказівник на масив array
Змінна, яка зберігає значення розміру масиву counter
Змінна, яка зберігає значення, що відповідає обраному користувачем типу сортування sortingType*/
int workWithArray(double* array, int counter, int type_of_sorting) {
    clock_t start_t = 0, //змінна для фіксації початкового часу роботи функції сортування 
        end_t = 0; //змінна для фіксації кінцевого часу роботи функції сортування 
    long double total_t; //змінна для фіксації часу роботи функції сортування 

    switch (type_of_sorting) {
    case 1: {
        sortInsert(array, counter, start_t, end_t, &total_t);
        break;
    }
    case 2: {
        mergeSort(array, 0, counter - 1, start_t, end_t, &total_t);
        break;
    }
    case 3: {
        if (bucketSort(array, counter, start_t, end_t, &total_t) == 1)
            return 1;
        break;
    }
    }

    printf("\nАлгоритм був виконаний за %lf секунд \n", total_t);

    return 0;
}

/*Функція реалізації алгоритма сортування підрахунком
Зміст параметрів, що передаються:
Вказівник на масив arr
Кількість елементів масиву n*/
void sortInsert(double* arr, int n, clock_t start_t, clock_t end_t, long double* total_t) {
    start_t = clock();

    int i, j, temp;

    for (i = 1; i < n; i++) { // основний цикл
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp <= arr[j]) { // внутрішній цикл зсуву
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    end_t = clock();
    *total_t = (long double)(end_t - start_t) / CLK_TCK;
}

/*Функція реалізації алгоритма сортування злиття
Зміст параметрів, що передаються:
Вказівник на масив array[]
Змінна лівого краю розглядаємої частини масиву left
Змінна правого краю розглядаємої частини масиву right
Змінна для запису часу початку виконання функції start_t
Змінна для запису часу кінця виконання функції end_t
Змінна для запису часу виконання функції total_t*/
void mergeSort(double array[], int left, int right, clock_t start_t, clock_t end_t, long double* total_t)
{
    start_t = clock();

    if (left < right)
    {
        int middle = left + (right - left) / 2;

        //Сортує першу та другу половинки 
        mergeSort(array, left, middle, start_t, end_t, total_t);
        mergeSort(array, middle + 1, right, start_t, end_t, total_t);

        merge(array, left, middle, right);
    }

    end_t = clock();
    *total_t = (long double)(end_t - start_t) / CLK_TCK;
}

// З'єднує 2 масива, утворені з масиву arr[].
// Перший масив-L[l..m]
// Другий масив-R[m+1..r]
void merge(double* arr, int l, int m, int r)
{
    int i, j, k; //індекси для першого, другого та з'єднаного масиву, який заповнюємо з масиву arr[]
    int n1 = m - l + 1; //кількість елементів у першому тимчасовому масиві
    int n2 = r - m; //кількість елементів у другому тимчасовому масиві

    /*Показники на тимчасові масиви, які заповнимо з масиву arr[]*/
    double* L = NULL;
    double* R = NULL;

    L = (double*)malloc(n1 * sizeof(double));
    R = (double*)malloc(n2 * sizeof(double));

    /*Копіюємо дані у масиви L[] та R[]*/
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /*З'єднуємо масиви назад у масив[l..r]*/
    i = 0; // Ініціалізуємо індекс для першого масиву, який заповнюємо з масиву arr[]
    j = 0; // Ініціалізуємо індекс для другого масиву, який заповнюємо з масиву arr[]
    k = l; // Ініціалізуємо індекс для з'єднаного масиву, який заповнюємо з масиву arr[]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /*Копіюємо залишкові елементи з L[], якщо такі є*/
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /*Копіюємо залишкові елементи з R[], якщо такі є*/
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    /*Звільнення пам'яті, що була виділена під динамічні масиви L[] i R[]*/
    free(L);
    free(R);
}

/*Функція для порівняння двох елементів. Ця функція використовується
бібліотечною функцією qsort
Вхід:
Перша змінна для порівняння
Друга змінна для порівняння*/
int compareIntegers(const void* first, const void* second) {
    int a = *((double*)first), //перше число для порівняння
        b = *((double*)second); //друге число для порівняння

    if (a == b)
    {
        return 0;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 1;
    }

}

/*Функція реалізації алгоритма сортування комірками
Вхід:
Вказівник на масив array
Змінна, що зберігає кількість елементів масиву
Змінна для запису часу початку виконання функції start_t
Змінна для запису часу кінця виконання функції end_t
Змінна для запису часу виконання функції total_t*/
int bucketSort(double* array, int n, clock_t start_t, clock_t end_t, long double* total_t) {
    start_t = clock();

    bucket buckets[2]; // масив типу структури bucket для зберігання даних з матриці для сортування
    int i, j, k; // бігунки для циклів for
    for (i = 0; i < 2; i++) {
        buckets[i].count = 0; // скидання лічильника
        buckets[i].values = (double*)malloc(sizeof(double) * n); // виділення блока пам'яті
        if (!buckets[i].values)
            return 1; // повернення при нестачі пам'яті!
    }
    // Розділяємо несортовані елементи по двох комірках
    for (i = 0; i < n; i++) {
        if (array[i] < 0) { // якщо елемент < 0 : до першої комірки
            buckets[0].values[buckets[0].count++] = array[i];
        }
        else { // якщо елемент >=0 : до другої комірки
            buckets[1].values[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 2; i++) {
        /*Використовуємо Quicksort для сортування кожної комірки */
        qsort(buckets[i].values, buckets[i].count, sizeof(double), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++) { //переносимо відсортовані елементи з кожної комірки до основного масиву

            array[k + j] = buckets[i].values[j];
        }
        k += buckets[i].count; //коригування індекса відсортованого масиву
        free(buckets[i].values); //звільнення пам'яті

    }

    end_t = clock();
    *total_t = (long double)(end_t - start_t) / CLK_TCK;

    return 0; //нормальне повернення з функціі – масив відсортований
}