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
    double* values; // вказівник на елемент масиву
};

/* Прототипи функцій */
void check(int left, int right, int flag);
void fclose_check(FILE*& fr, char filename[]);
void to_file(FILE*& fp, int num_of_elements, double* arr);
int enter(int& N);
void сheck_enter(char filename[]);
int element_counter(FILE*& fd);
void from_file(FILE* fp, int size, double* array);
int sorting(double* array, int counter, int type_of_sorting);
void sortBubble(double* arr, int n, clock_t start_t, clock_t end_t, long double* total_t);
void partition(double* arr, int beg, int end, int* loc);
void quickSort(double* arr, int beg, int end);
int compareIntegers(const void* first, const void* second);
int bucketSort(double array[], int n, clock_t start_t, clock_t end_t, long double* total_t);

int main(int argc, char* argv[]) {
    FILE* fr = NULL; //файловий дескриптор для встановлення потоку з файлом
    FILE* fr2 = NULL; //файловий дескриптор для встановлення потоку з файлом
    double* array = NULL; //покажчик на масив для зберігання даних
    double* temp_array = NULL; //покажчик на додатковий масив для зберігання даних
    int sortingType = 0, //змінна пункту меню, яка відповідає за вибір типу сортування
        fillingType = 0, //змінна пункту меню, яка відповідає за вибір типу заповнення масиву
        minimum, //змінна для зберігання значення лівої границі для генерації випадкових чисел
        maximum, //змінна для зберігання значення правої границі для генерації випадкових чисел
        counter = 0, //розмір масиву
        flag; //змінна для повторного запуску програми
    char filename[256]; //рядок з назвою першого файлу
    char filename2[256]; //рядок з назвою другого файлу

    SetConsoleCP(1251); //підключення кирилиці
    SetConsoleOutputCP(1251);

    for (;;) {
        srand(time(NULL)); //встановлює поточний час як базу для функції "rand()"

        do {
            printf("Виберіть тип сортування:\n1)Сортування бульбашкою;\n2)Швидке сортування;\n3)Сортування комірками.\n0)Завершити програму;\n");
            enter(sortingType); //зчитування пункту меню
            check(0, 3, sortingType); //перевірка коректності введеного значення
        } while (sortingType < 0 || sortingType > 3);

        if (sortingType == 0) {
            printf("Робота програми завершена!\n");
            return 0;
        }

        do {
            printf("Оберіть те, як Ви бажаєте працювати з масивом:\n1)Ввести дані для нього з файлу;\n2)Заповнити файл випадковими числами і зчитати їх звідти;\n3)Тестовий режим(заповнення файлу з клавіатури в консоль).\n0)Перейти на початок\n");
            enter(fillingType); //зчитування пункту меню
            check(0, 3, fillingType); //перевірка коректності введеного значення
        } while (fillingType < 0 || fillingType > 3);

        if (fillingType == 0) {
            system("cls");
            continue;
        }

        switch (fillingType) {
        case 1: {
            printf("Введіть назву файлу у вигляді name.txt, з якого бажаєте зчитати дані для масиву:\n");
            сheck_enter(filename); //перевірка правильності введення назви файла
            if ((fr = fopen(filename, "r")) == NULL) //вiдкриття файлу, та перевірка на помилки
            {
                printf("Виникла помилка при відкритті файлу %s! \n", filename);
                return 0;
            }

            printf("Введіть назву файлу у вигляді name.txt, до якого бажаєте переписати відсортований масив:\n");
            сheck_enter(filename2); //перевірка правильності введення назви файла
            if ((fr2 = fopen(filename2, "w")) == NULL) //вiдкриття файлу, та перевірка на помилки
            {
                printf("Виникла помилка при відкритті файлу %s! \n", filename);
                return 0;
            }

            counter = element_counter(fr);
            array = (double*)malloc(counter * sizeof(double));
            from_file(fr, counter, array); //зчитування даних з файлу і запису їх до комірок масиву
            fclose(fr); //закриття файлу
            fclose_check(fr, filename); //перевірка закриття файлу на помилки
            break;
        }
        case 2: {
            printf("Введіть назву файлу у вигляді name.txt, з якого після заповнення бажаєте зчитати дані для масиву:\n");
            сheck_enter(filename); //перевірка правильності введення назви файла
            if ((fr = fopen(filename, "w")) == NULL) //вiдкриття файлу, та перевірка на помилки
            {
                printf("Виникла помилка при відкритті файлу %s! \n", filename);
                return 0;
            }

            printf("Введіть назву файлу у вигляді name.txt, до якого бажаєте переписати відсортований масив:\n");
            сheck_enter(filename2); //перевірка правильності введення назви файла

            if ((fr2 = fopen(filename2, "w")) == NULL) //вiдкриття файлу, та перевірка на помилки
            {
                printf("Виникла помилка при відкритті файлу %s! \n", filename);
                return 0;
            }

            printf("Введіть кількість елементів масиву:\n");
            enter(counter); //зчитування кількості елементів масиву

            if (counter < 1) {
                printf("Введене некоректне значення!");
                exit(0);
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
                    exit(0);
                }
            } while (maximum < minimum);

            for (int i = 0; i < counter; i++) {
                temp_array[i] = minimum + rand() % (maximum - minimum + 1);
            }

            to_file(fr, counter, temp_array); //записуємо в файл отриманий масив

            fclose(fr); //закриття файлу

            fclose_check(fr, filename); //перевірка закриття файлу на помилки

            free(temp_array); //звільняємо пам'ять динамічного масиву

            if ((fr = fopen(filename, "r")) == NULL) //вiдкриття файлу, та перевірка на помилки
            {
                printf("Виникла помилка при відкритті файлу %s! \n", filename);
                return 0;
            }

            from_file(fr, counter, array); //зчитування даних з файлу і запису їх до комірок масиву

            fclose(fr); //закриття файлу

            fclose_check(fr, filename); //перевірка закриття файлу на помилки

            break;
        }
        case 3: {
            printf("Введіть назву файлу у вигляді name.txt, з якого після заповнення бажаєте зчитати дані для масиву:\n");
            сheck_enter(filename); //перевірка правильності введення назви файла

            if ((fr = fopen(filename, "w")) == NULL) //вiдкриття файлу, та перевірка на помилки
            {
                printf("Виникла помилка при відкритті файлу %s! \n", filename);
                return 0;
            }

            printf("Введіть назву файлу у вигляді name.txt, до якого бажаєте переписати відсортований масив:\n");
            сheck_enter(filename2); //перевірка правильності введення назви файла

            if ((fr2 = fopen(filename2, "w")) == NULL) //вiдкриття файлу, та перевірка на помилки
            {
                printf("Виникла помилка при відкритті файлу %s! \n", filename);
                return 0;
            }

            printf("Введіть кількість елементів масиву:\n");
            enter(counter); //зчитування кількості елементів масиву

            if (counter < 1) {
                printf("Введене некоректне значення!");
                exit(0);
            }

            array = (double*)malloc(counter * sizeof(double));
            temp_array = (double*)malloc(counter * sizeof(double));

            for (int i = 0; i < counter; i++) {
                printf("Введіть елемент [%d] масиву:\n", i + 1);
                scanf("%lf", &temp_array[i]);
            }
            to_file(fr, counter, temp_array); //записуємо в файл отриманий масив

            free(temp_array); //звільняємо пам'ять динамічного масиву

            fclose(fr); //закриття файлу

            fclose_check(fr, filename); //перевірка закриття файлу на помилки

            if ((fr = fopen(filename, "r")) == NULL) //вiдкриття файлу, та перевірка на помилки
            {
                printf("Виникла помилка при відкритті файлу %s! \n", filename);
                return 0;
            }

            from_file(fr, counter, array); //зчитування даних з файлу і запису їх до комірок масиву

            fclose(fr); //закриття файлу

            fclose_check(fr, filename); //перевірка закриття файлу на помилки

            break;
        }
        }

        if (sorting(array, counter, sortingType) == 1) { // сортування даних з перевіркою
            printf("Не вистачає пам'яті!");
            free(array); //звільняємо пам'ять динамічного масиву
            fclose(fr2); //закриття файлу
            fclose_check(fr2, filename2); //перевірка закриття файлу на помилки
            continue;
        }

        to_file(fr2, counter, array); //записування масиву у файл

        free(array); //звільняємо пам'ять динамічного масиву

        fclose(fr2); //закриття файлу

        fclose_check(fr2, filename2); //перевірка закриття файлу на помилки

    }
}

/*Функція перевірки коректності введеного значення
Вхід:
Змінна лівої границі перевірки
Змінна правої границі перевірки
Змінна значення для перевірки
Вихід:
Відсутній*/
void check(int left, int right, int flag) {
    if (flag < left || flag > right) {
        printf("Ви ввели некоректне значення, спробуйте ще раз!\n");
    }
}

/*Функція перевірки файлу на закриття без помилок
Вхід:
Файловий дескриптор fp
Масив, у якому записана назва файлу, яку ввів користувач filename[]
Вихід:
Відсутній*/
void fclose_check(FILE*& fp, char filename[]) {
    if (ferror(fp)) {
        printf("Помилка при закритті файлу %s", filename);
        exit(0);
    }
}

/*Функція записування масиву у файл
Вхід:
Файловий дескриптор fp
Змінна, яка зберігає значення розміру масиву counter
Вказівник на масив array
Вихід:
Відсутній
*/
void to_file(FILE*& fp, int num_of_elements, double* arr) {
    for (int i = 0; i < num_of_elements; i++) {
        if (!fprintf(fp, "%lf\n", arr[i]))
        {
            printf("Щось пішло не так!\n");
            exit(0);
        }
    }
}

/*Функція to_scan
Функція введення значень змінних
Вхід:
N-змінна для заповнення, передача за посиланням
Вихід:
Змінна з записаним числом*/
int enter(int& N) {
    int entered = 0; //змінна для контролю введених користувачем з клавіатури символів
    do {
        do {
            entered = scanf_s("%d%*c", &N);
            while (entered < 1) {
                printf("Ви ввели некоректне значення,повторіть введення: ");
                entered = scanf_s("%d%*c", &N);
            }
        } while (entered < 1);
    } while (entered != 1);
    return N;
}

/*Функція для перевірки правильності введення назви файлів
Вхід:
Масив, у якому записана назва файлу, яку ввів користувач filename[]
Вихід:
Відсутній
*/
void сheck_enter(char filename[]) {
    int fcheck = 0; //змінна для контролю правильності вводу назви файлу користувачем
    int scheck = 0; //змінна для контролю правильності вводу назви файлу користувачем
    do {
        fgets(filename, 1024, stdin);
        fcheck = 1;
        scheck = 0;
        for (int i = 0; i < strlen(filename); i++)
        {
            if (filename[i] == '.' && i != 0)
            {
                scheck = 1;
                if (filename[i + 1] != 't' || filename[i + 2] != 'x' || filename[i + 3] != 't' || filename[i + 4] != '\n')
                {
                    printf("Ви ввели розширення не вірно, спробуйте ще раз!\n");
                    fcheck = 0;
                }
            }
        }
        if (filename[0] == '\n')
        {
            printf("Ви нічого не ввели, спробуйте ще раз!\n");
        }

        if (scheck == 0 && filename[0] != '\n')
        {
            printf("Ви не ввели розширення, спробуйте ще раз!\n");
        }
    } while (filename[0] == '\n' || fcheck == 0 || scheck == 0);
    filename[strlen(filename) - 1] = '\0'; //змінює \n на \0
}

/*Функція для підрахунку кількості елементів у файлі
Вхід:
Файловий дескриптор fd
Значення, що повертається функцією:
Кількість елементів у файлі - count
Вихід:
Змінна count, яка зберігає кількість елементів у файлі*/
int element_counter(FILE*& fd) {
    int count = 0; //змінна для підрахунку кількості елементів, що зберігається у файлі

    while (!feof(fd)) { //поки не дійшли до кінця файлу
        fscanf(fd, "%*lf");
        count++;
    }
    rewind(fd); //переміщує показник в початок файлу
    if (ferror(fd)) {
        printf("Не переміщено показник в початок файлу\n");
        exit(0);
    }
    return count;
}

/*Функція для зчитування даних з файлу і запису їх до комірок масиву array[]
Вхід:
Файловий дескриптор fp
Змінна, яка зберігає значення кількості елементів у файлі size
Вказівник на масив array
Вихід:
Відсутній*/
void from_file(FILE* fp, int size, double* array)
{
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%lf", &(*((double*)array + i)));
    }
}

/*Функція sorting для надсилання даних з масиву на сортування, яке обрав користувач
Вхід:
Вказівник на масив array
Змінна, яка зберігає значення розміру масиву counter
Змінна, яка зберігає значення, що відповідає обраному користувачем типу сортування sortingType
Вихід:
Ціле число, як результат виконання функції
*/
int sorting(double* array, int counter, int type_of_sorting) {
    clock_t start_t = 0, //змінна для фіксації початкового часу роботи функції сортування 
        end_t = 0; //змінна для фіксації кінцевого часу роботи функції сортування 
    long double total_t; //змінна для фіксації часу роботи функції сортування 

    switch (type_of_sorting) {
    case 1: {
        sortBubble(array, counter, start_t, end_t, &total_t);
        break;
    }
    case 2: {
        start_t = clock();

        quickSort(array, 0, counter - 1);

        end_t = clock();
        total_t = (long double)(end_t - start_t) / CLK_TCK;
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

/* Функція sortBubble - сортування бульбашкою
Вхід:
Вказівник на масив arr
Змінна, що зберігає кількість елементів масиву
Змінна для запису часу початку виконання функції start_t
Змінна для запису часу кінця виконання функції end_t
Змінна для запису часу виконання функції total_t
Вихід:
Відсутній*/
void sortBubble(double* arr, int n, clock_t start_t, clock_t end_t, long double* total_t) {
    start_t = clock();

    int j, /* лічильник циклу */
        notSorted = 1, /* ознака невпорядкованості */
        temp; /* тимчасова проміжна змінна при обміні */

    while (notSorted) { // цикл виконується за наявності не впорядкованості
        notSorted = 0; // скидання ознаки невпорядкованості
        // проходження по масиву в пошуках невпорядкованих пар
        for (j = 0; j < n - 1; j++) {
            // якщо пара знайдена - міняємо елементи пари місцями
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                notSorted = 1; // встановлюємо ознаку невпорядкованості
            }
        }
    }
    end_t = clock();

    *total_t = (long double)(end_t - start_t) / CLK_TCK;
}

/* Функція partition - пошук опорного елемента і поділу
сортованого масиву на дві частини
Вхід:
Вказівник на масив arr
Опорний елемент сортування
Змінна, що зберігає кількість елементів масиву
Змінна, яка містить індекс опорного елемента в масиві
Вихід:
Відсутній*/
void partition(double* arr, int beg, int end, int* loc) {
    int flag = 0; // флаг закінчення поділу
    int temp; // проміжна змінна для обміну значень в поточному підмасиві
    int left = *loc = beg; // індекс елементу лівої границі, елемент на початку масиву
    int right = end; // індекс елементу правої границі, останній елемент

    while (!flag) { // виконуємо, поки не "розбили" масив на два підмасива 
    /* Йдемо справа наліво по масиву */
        while (arr[*loc] <= arr[right] && *loc != right)
            right--;
        if (*loc == right) flag = 1; // розбиття масиву і робота алгоритму закінчена 
        else if (arr[*loc] > arr[right]) {
            temp = arr[right];
            arr[right] = arr[*loc];
            arr[*loc] = temp;
            *loc = right;
        }
        /* Тепер рухаємося зліва направо по масиву, */
        if (!flag) {
            while (arr[*loc] >= arr[left] && *loc != left)
                left++;
            if (*loc == left) flag = 1; // розбиття масиву і робота алгоритму закінчена 
            else if (arr[*loc] < arr[left]) {
                temp = arr[left];
                arr[left] = arr[*loc];
                arr[*loc] = temp;
                *loc = left;
            }
        }
    } // кінець циклу while (!flag)
}

/* Функція quickSort - швидке сортування
Вхід:
Вказівник на масив arr
Опорний елемент сортування
Змінна, що зберігає кількість елементів масиву
Вихід:
Відсутній
*/
void quickSort(double* arr, int beg, int end) {
    int loc; //змінна, яка містить індекс опорного елемента в масиві
    if (beg < end) {
        partition(arr, beg, end, &loc);
        quickSort(arr, beg, loc - 1);
        quickSort(arr, loc + 1, end);
    }
}

/*Функція compareIntegers - порівняння двох елементів. Використовується
бібліотечною функцією qsort
Вхід:
Перша змінна для порівняння
Друга змінна для порівняння
Вихід:
Ціле число, як результат виконання функції
*/
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

/*Функція bucketSort - сортування комірками
Вхід:
Вказівник на масив array
Змінна, що зберігає кількість елементів масиву
Змінна для запису часу початку виконання функції start_t
Змінна для запису часу кінця виконання функції end_t
Змінна для запису часу виконання функції total_t
Вихід:
Ціле число, як результат виконання функції
*/
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