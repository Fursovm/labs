#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "locale.h"
#include "windows.h"
#include "time.h"


void check(int left, int right, int flag);
void fopen_check(FILE*& fr, char filename[], char d);
void fclose_check(FILE*& fr, char filename[]);
void to_file(FILE*& fp, int num_of_elements, double* arr);
void to_file(FILE*& fp, int num_of_elements, int* arr);
int to_scan(int& N);
void scan(char filename[]);
int element_counter(FILE*& fd);
void from_file(FILE* fp, int size, double* array);
void from_file(FILE* fp, int size, int* array);
void sorting(double* array, int counter, int type_of_sorting);
void sorting(int* array, int counter, int type_of_sorting);
void sortBubble(double* arr, int n, clock_t start_t, clock_t end_t, long double* total_t);
void partition(double* arr, int beg, int end, int* loc);
void quickSort(double* arr, int beg, int end, clock_t start_t, clock_t end_t, long double* total_t);
void sortCount(double* a, int n, clock_t start_t, clock_t end_t, long double* total_t);
void sortCount(int* a, int n, clock_t start_t, clock_t end_t, long double* total_t);


int main(int argc, char* argv[]) {
    FILE* fr = NULL; //файловий дескриптор для встановлення потоку з файлом
    FILE* fr2 = NULL; //файловий дескриптор для встановлення потоку з файлом
    double* array = NULL; //покажчик на масив для зберігання даних
    double* temp_array = NULL; //покажчик на додатковий масив для зберігання даних
    int type_of_sorting = 0, //змінна пункту меню, яка відповідає за вибір типу сортування
        type_of_filling = 0, //змінна пункту меню, яка відповідає за вибір типу заповнення масиву
        minimum, //змінна для зберігання значення лівої границі для генерації випадкових чисел
        maximum, //змінна для зберігання значення правої границі для генерації випадкових чисел
        counter = 0, //розмір масиву
        flag; //змінна для повторного запуску програми
    char filename[256]; //рядок з назвою першого файлу
    char filename2[256]; //рядок з назвою другого файлу

    SetConsoleCP(1251); //підключення кирилиці
    SetConsoleOutputCP(1251);

    do {
        // system("cls");
        srand(time(NULL)); //встановлює поточний час як базу для функції "rand()"

        do {
            printf("Виберіть тип сортування:\n0)Завершити програму;\n1)Сортування змішуванням;\n2)Швидке сортування;\n3)Сортування комірками.\n");
            to_scan(type_of_sorting); //зчитування пункту меню
            check(0, 3, type_of_sorting); //перевірка коректності введеного значення
        } while (type_of_sorting < 0 || type_of_sorting > 3);

        if (type_of_sorting == 0) {
            printf("Робота програми завершена!\n");
            return 0;
        }

        do {
            printf("Оберіть те, як Ви бажаєте працювати з масивом:\n0)Завершити програму;\n1)Ввести дані для нього з файлу;\n2)Заповнити файл випадковими числами і зчитати їх звідти;\n3)Тестовий режим(заповнення файлу з клавіатури в консоль).\n");
            to_scan(type_of_filling); //зчитування пункту меню
            check(0, 3, type_of_filling); //перевірка коректності введеного значення
        } while (type_of_filling < 0 || type_of_filling > 3);

        if (type_of_filling == 0) {
            printf("Робота програми завершена!\n");
            return 0;
        }

        switch (type_of_filling) {
        case 1: {
            printf("Введіть назву файлу у вигляді name.txt, з якого бажаєте зчитати дані для масиву:\n");
            scan(filename); //перевірка правильності введення назви файла
            fopen_check(fr, filename, 'r'); //вiдкриття файлу, та перевірка на помилки

            printf("Введіть назву файлу у вигляді name.txt, до якого бажаєте переписати відсортований масив:\n");
            scan(filename2); //перевірка правильності введення назви файла
            fopen_check(fr2, filename2, 'w'); //вiдкриття файлу, та перевірка на помилки

            counter = element_counter(fr);

            if (type_of_sorting == 3) {
                int* array = (int*)malloc(counter * sizeof(int));
            }
            else {
                double* array = (double*)malloc(counter * sizeof(double));
            }

            from_file(fr, counter, array); //зчитування даних з файлу і запису їх до комірок масиву
            fclose(fr); //закриття файлу
            fclose_check(fr, filename); //перевірка закриття файлу на помилки
            break;
        }
        case 2: {
            printf("Введіть назву файлу у вигляді name.txt, з якого після заповнення бажаєте зчитати дані для масиву:\n");
            scan(filename); //перевірка правильності введення назви файла
            fopen_check(fr, filename, 'w'); //вiдкриття файлу, та перевірка на помилки

            printf("Введіть назву файлу у вигляді name.txt, до якого бажаєте переписати відсортований масив:\n");
            scan(filename2); //перевірка правильності введення назви файла
            fopen_check(fr2, filename2, 'w'); //вiдкриття файлу, та перевірка на помилки

            printf("Введіть кількість елементів масиву:\n");
            to_scan(counter); //зчитування кількості елементів масиву

            if (counter < 1) {
                printf("Введене некоректне значення!");
                exit(0);
            }

 
            if (type_of_sorting == 3) {
                int* array = (int*)malloc(counter * sizeof(int));
                int* temp_array = (int*)malloc(counter * sizeof(int));
            }
            else {
                double* array = (double*)malloc(counter * sizeof(double));
                double* temp_array = (double*)malloc(counter * sizeof(double));
            }

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

            fopen_check(fr, filename, 'r'); //вiдкриття файлу, та перевірка на помилки

            from_file(fr, counter, array); //зчитування даних з файлу і запису їх до комірок масиву

            fclose(fr); //закриття файлу

            fclose_check(fr, filename); //перевірка закриття файлу на помилки

            break;
        }
        case 3: {
            printf("Введіть назву файлу у вигляді name.txt, з якого після заповнення бажаєте зчитати дані для масиву:\n");
            scan(filename); //перевірка правильності введення назви файла

            fopen_check(fr, filename, 'w'); //вiдкриття файлу, та перевірка на помилки

            printf("Введіть назву файлу у вигляді name.txt, до якого бажаєте переписати відсортований масив:\n");
            scan(filename2); //перевірка правильності введення назви файла

            fopen_check(fr2, filename2, 'w'); //вiдкриття файлу, та перевірка на помилки

            printf("Введіть кількість елементів масиву:\n");
            to_scan(counter); //зчитування кількості елементів масиву

            if (counter < 1) {
                printf("Введене некоректне значення!");
                exit(0);
            }

            for (int i = 0; i < counter; i++) {
                printf("Введіть елемент [%d] масиву:\n", i + 1);
                scanf("%lf", &temp_array[i]);
            }
            to_file(fr, counter, temp_array); //записуємо в файл отриманий масив

            free(temp_array); //звільняємо пам'ять динамічного масиву

            fclose(fr); //закриття файлу

            fclose_check(fr, filename); //перевірка закриття файлу на помилки

            fopen_check(fr, filename, 'r'); //вiдкриття файлу, та перевірка на помилки

            from_file(fr, counter, array); //зчитування даних з файлу і запису їх до комірок масиву

            fclose(fr); //закриття файлу

            fclose_check(fr, filename); //перевірка закриття файлу на помилки

            break;
        }
        }

        sorting(array, counter, type_of_sorting); // сортування даних
        to_file(fr2, counter, array); //записування масиву у файл
        free(array); //звільняємо пам'ять динамічного масиву
        fclose(fr2); //закриття файлу
        fclose_check(fr2, filename2); //перевірка закриття файлу на помилки

        do {
            printf("\n0)Завершити програму;\n1)Продовжити роботу програми\n");
            to_scan(flag); //зчитування пункту меню
            check(0, 1, flag); //перевірка коректності введеного значення
        } while (flag < 0 || flag > 1);

    } while (flag == 1);

    printf("\nРобота програми завершена!\n");

    return 0;
}

/*Функція перевірки коректності введеного значення*/
void check(int left, int right, int flag) {
    if (flag < left || flag > right) {
        printf("Ви ввели некоректне значення, спробуйте ще раз!\n");
    }
}

/*Функція вiдкриття файлу, та перевірки на помилки*/
void fopen_check(FILE*& fp, char filename[], char d) {
    if (d == 'r') {
        if ((fp = fopen(filename, "r")) == NULL)
        {
            printf("Виникла помилка при відкритті файлу %s! \n", filename);
            exit(0);
        }
    }
    if (d == 'w') {
        if ((fp = fopen(filename, "w")) == NULL)
        {
            printf("Виникла помилка при відкритті файлу %s! \n", filename);
            exit(0);
        }
    }
}

/*Функція перевірки файлу на закриття без помилок*/
void fclose_check(FILE*& fp, char filename[]) {
    if (ferror(fp)) {
        printf("Помилка при закритті файлу %s", filename);
        exit(0);
    }
}

/*Функція записування масиву у файл*/
void to_file(FILE*& fp, int num_of_elements, double* arr) {
    for (int i = 0; i < num_of_elements; i++) {
        if (!fprintf(fp, "%lf ", arr[i]))
        {
            printf("Щось пішло не так!\n");
            exit(0);
        }
    }
}

void to_file(FILE*& fp, int num_of_elements, int* arr) {
    for (int i = 0; i < num_of_elements; i++) {
        if (!fprintf(fp, "%lf ", arr[i]))
        {
            printf("Щось пішло не так!\n");
            exit(0);
        }
    }
}

/*Функція введення значень змінних*/
int to_scan(int& N) {
    int entered = 0; //змінна для контролю введених користувачем з клавіатури символів
    do {
        do {
            entered = scanf_s("%d", &N);
            while (getchar() != '\n');
            while (entered < 1) {
                printf("Ви ввели некоректне значення,повторіть введення: ");
                entered = scanf_s("%d", &N);
                while (getchar() != '\n');
            }
        } while (entered < 1);
    } while (entered != 1);
    return N;
}

/*Функція для перевірки правильності введення назви файлів*/
void scan(char filename[]) {
    int fcheck = 0; //змінна для контролю правильності вводу назви файлу користувачем
    int scheck = 0; //змінна для контролю правильності вводу назви файлу користувачем
    do {
        fgets(filename, 1024, stdin);
        fcheck = 1;
        scheck = 0;
        for (int i = 0; i < strlen(filename); i++)
        {
            if (filename[i] == '.')
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

/*Функція для підрахунку кількості елементів у файлі*/
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

/*Функція для зчитування даних з файлу і запису їх до комірок масиву array[]*/
void from_file(FILE* fp, int size, double* array)
{
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%lf", &(*((double*)array + i)));
    }
}

void from_file(FILE* fp, int size, int* array)
{
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%lf", &(*((int*)array + i)));
    }
}

/*Функція для надсилання даних з масиву на сортування, яке обрав користувач*/
void sorting(double* array, int counter, int type_of_sorting)
{
    clock_t start_t = 0, //змінна для фіксації початкового часу роботи функції сортування 
        end_t = 0; //змінна для фіксації кінцевого часу роботи функції сортування 
    long double total_t; //змінна для фіксації часу роботи функції сортування 

    switch (type_of_sorting) {
    case 1: {
        sortBubble(array, counter, start_t, end_t, &total_t);
        break;
    }
    case 2: {
        quickSort(array, 0, counter - 1, start_t, end_t, &total_t);
        break;
    }
    }

    printf("\nАлгоритм був виконаний за %lf секунд \n", total_t);
}

void sorting(int* array, int counter, int type_of_sorting) {
    clock_t start_t = 0, //змінна для фіксації початкового часу роботи функції сортування 
            end_t = 0; //змінна для фіксації кінцевого часу роботи функції сортування 
    long double total_t; //змінна для фіксації часу роботи функції сортування 

    sortCount(array, counter, start_t, end_t, &total_t);
 
    printf("\nАлгоритм був виконаний за %lf секунд \n", total_t);
}

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

/* функція, що реалізує алгоритм пошуку опорного елемента і поділу
сортованого масиву на дві частини */
void partition(double* arr, int beg, int end, int* loc) {
    int flag, // флаг закінчення поділу
        temp, // проміжна змінна для обміну значень в поточному підмасиві
        left, right; // лівий та правий рухомі індекси
        // ініціалізація алгоритму, відповідно до п. 1 Приклад 10.3
    left = *loc = beg;
    right = end;
    flag = 0;
    while (!flag) { /* виконуємо, поки не "розбили" масив на два підмасива */
    // Йдемо справа наліво по масиву
        while (arr[*loc] <= arr[right] && *loc != right)
            right--;
        if (*loc == right) /* розбиття масиву і робота алгоритму закінчена */
            flag = 1;
        else if (arr[*loc] > arr[right]) {
            temp = arr[right];
            arr[right] = arr[*loc];
            arr[*loc] = temp;
            *loc = right;
        }
        /* тепер рухаємося зліва направо по масиву, */
        if (!flag) {
            while (arr[*loc] >= arr[left] && *loc != left)
                left++;
            if (*loc == left) /* розбиття масиву і робота алгоритму закінчена */
                flag = 1;
            else if (arr[*loc] < arr[left]) {
                temp = arr[left];
                arr[left] =
                    arr[*loc];
                arr[*loc] =
                    temp;
                *loc = left;
            }
        }
    } // кінець циклу while (!flag)
    return;
}

/* Функція, що реалізує в собі алгоритм швидкого сортування */
void quickSort(double* arr, int beg, int end, clock_t start_t, clock_t end_t, long double* total_t) {
    start_t = clock();
    int loc;
    if (beg < end) {
        partition(arr, beg, end, &loc);
        quickSort(arr, beg, loc - 1, start_t, end_t, total_t);
        quickSort(arr, loc + 1, end, start_t, end_t, total_t);
    }

    end_t = clock();
    *total_t = (long double)(end_t - start_t) / CLK_TCK;
    return;
}

void sortCount(double* a, int n, clock_t start_t, clock_t end_t, long double* total_t) {
    int* c, /* масив лічильників */
        i, j, /* лічильники циклів */
        b, /* допоміжний індекс для вхідного масиву */
        size; /* розмір масиву лічильників */

    // визначаємо розмір масиву лічильників
    size = a[0];
    for (i = 0; i < n; i++)
        if (size < a[i])
            size = a[i];
    size++; /* розмір масиву (тому, що рахуємо від нуля!) */
    c = (int*)calloc(size, sizeof(int)); /* створюємо масив лічильників */
   
    for (i = 0; i < n; i++) {
        c[a[i]]++;
    }

    // заповнення вхідного масиву відсортованими значеннями
    b = 0;
    for (j = 0; j < size; j++)
        for (i = 0; i < c[j]; i++) {
            a[b] = j;
            b++;
        }
    free(c);
}