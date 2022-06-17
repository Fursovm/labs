#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "locale.h"
#include "windows.h"
#include "time.h"
#include <math.h>
#include "assert.h"
#define Distance 15
#define SIZE 3

/*Структура з ключем і цілим числом вузла дерева*/
struct DataAndKeys {
    int data; //ціле число вершини
    char* key; //ключ вершини
};

/*Структура вузла дерева*/
struct BTNode { //вершина дерева
    struct BTNode* left; //вказівник на лівий нащадок
    DataAndKeys treeData; //ключ і ціле число вершини
    struct BTNode* right; //вказівник на правий нащадок
};

/*Формат дескриптора дерева*/
struct BTDescriptor { //дескриптор дерева
    int size; //число вершин
    BTNode* root; //корінь дерева
};

/*Структура стовбура дерева*/
struct Trunk
{
    Trunk* prev; //попередній елемент
    char* str; //для друку з'єднань елементів дерева
};

/*Прототипи функцій*/
BTDescriptor* createTree(void);    // Функція створення дерева
BTNode* initializeNode(const DataAndKeys* entry);  // Функція створення вершини дерева та ініціалізації її полів
BTNode* findSmallestElement(BTNode* tree);  // Рекурсивна функція знаходження мінімального елемента у дереві
BTNode* deleteElement(BTNode* subTree, char* key, int num);  // Функція вилучення елемента з дерева
int numberScan(int& N);  // Функція введення значень змінних
int elementCounter(FILE*& fd);  // Функція для підрахунку кількості елементів у файлі
int getDataAndKeys(BTNode* tree, DataAndKeys* dAK, int* j);  // Функція перепису інформації вершин дерева до масиву структурного типу
int compareDataAndKeys(DataAndKeys* left, DataAndKeys* right);  // Функція перепису інформації вершин дерева до масиву структурного типу
int keyUsingSearch(BTNode* tree, char* key, int* noElementCheck, int* num);  // Функція пошуку елементу за ключем для виведення його на екран
int insertTree(BTDescriptor* dsTree, DataAndKeys* entry);  // Функція вставлення елемента в дерево
int freeStruct(DataAndKeys* dAK, int n);  // Функція звільнення пам'яті для масиву структурного типу
int printTree(BTNode* root, Trunk* prev, bool isLeft);  // Рекурсивна функція виводу на екран елементів дерева
int readFromFile(FILE* fp, int size, DataAndKeys* dAK);  // Функція для зчитування даних з файлу і запису їх до комірок масиву типу DataAndKeys
int writeToFile(FILE* fp, int size, DataAndKeys* dAK);  // Функція запису елементів масиву типу DataAndKeys до файлу
void checkFilename(char filename[]);  // Функція для перевірки правильності введення назви файлу
void getHeight(BTDescriptor* dsTree, BTNode* tree, int* height, int* curMaxHeight, int* prevMaxHeight);  // Функція визначення висоти дерева
void preOrder(BTNode* tree, int* j);  // Функція проходження дерева у прямому порядку
void postOrder(BTNode* tree, int* j);  // Функція проходження дерева у зворотньому порядку
void inOrder(BTNode* tree, int* j);  // Функція симетричного проходження дерева
void keyScan(char* key);  // Функція введення коректного ключа
void showTrunks(const Trunk* trunk);  // Рекурсивна функція виводу на екран з'єднань елементів дерева
void deleteTree(BTNode* tree);  // Функція видалення дерева

int main()
{
    FILE* fr = NULL; //для встановлення потоку з файлом
    int workWithBT; //для пункту меню
    int counter = 0; //кількость елементів у дереві
    int numberForLetter = 0; //код випадково згенерованої літери
    int minimum = 0; //нижня границя для генерації випадкових чисел
    int maximum = 0; //верхня границя для генерації випадкових чисел
    int noElementCheck = 1; //для перевірки на наявність елементу в дереві
    int elementNumber = 0; //код випадково згенерованого числа
    char filename[50]; //назва файлу
    bool flag = true; //для повторного вводу пункту меню
    bool flag1 = true; //для повторного вводу пункту меню
    char* forKey = NULL; //ключ, який користувач вводить з клавіатури
    int height = 0; //висота дерева
    int curMaxHeight = 0; //поточна максимальна висота дерева при проходженні його
    int maxHeight = 0; //максимальна висота дерева при проходженні його
    int count = 0; //кількість елементів у масиві структурного типу
    int fileReadCheck = 0; //для перевірки на помилки при зчитуванні елементів дерева з файлу
    int insertCheck = 0; //для перевірки на помилки при вставленні елемента
    int num = 0;

    SetConsoleCP(1251); //підключення кирилиці
    SetConsoleOutputCP(1251);

    srand((unsigned int)time(NULL));
    BTDescriptor* BTd = createTree(); //створюємо дерево

    if (BTd == NULL) { //перевірка на те, чи створене дерево
        printf("Дерево не створено!");
        return -1;
    }

    printf("Дерево створено!\n");
    do  {
        flag1 = true;
        do {
            flag = true;
            printf("1)Ввести існуюче дерево;\n2)Заповнити дерево вручну;\n3)Заповнити дерево випадковими числами.\n");
            numberScan(workWithBT); //зчитування пункту меню
            switch (workWithBT) {
            case 1: { //заповнення дерева з існуючого файлу
                printf("Введіть назву файлу у вигляді name.bin, з якого бажаєте зчитати дані:\n");
                checkFilename(filename); //перевірка правильності введення назви файла

                if ((fr = fopen(filename, "r")) == NULL)
                {
                    printf("Не вдалося відкрити файл із заданою назвою!\n");
                    exit(0);
                }

                counter = elementCounter(fr); //підрахунок кількості елементів у файлі
                if (counter == -1)
                {
                    printf("Помилка при переміщенні показника на початок файлу!\n");
                    exit(0);
                }
                DataAndKeys* dAK = (DataAndKeys*)malloc((counter) * sizeof(DataAndKeys)); //виділення пам'яті для масиву структурного типу
                if (!dAK) /*перевірка на те, чи пам'ять виділена під масив структурного типу*/
                {
                    printf("Недостатньо пам'яті для виділення її під масив\n!");
                    fclose(fr); //закриття потоку роботи з файлом
                    exit(0);
                }
                fileReadCheck = readFromFile(fr, counter, dAK); /*перенесення елементів з файлу до масиву структурного типу*/
                if (fileReadCheck == -1) //якщо не вдалося переписати елементи з файлу
                {
                    printf("Не вдалося переписати елементи з файлу!\n");
                    if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка*/
                    {
                        printf("Масиву структурного типу не існує!\n");
                        exit(0);
                    }
                }
                else if (fileReadCheck == -2) /*якщо ідентифікаційний код елемента в файлі не відповідає розміру в SIZE елементів*/
                {
                    printf("Ідентифікаційний код елемента в файлі не відповідає розміру в SIZE елементів!\n");
                    if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка*/
                    {
                        printf("Масиву структурного типу не існує!\n");
                        exit(0);
                    }
                }
                else if (fileReadCheck == -3) /*якщо не вийшло перемістити показник на початок файлу*/
                {
                    printf("Не вийшло перемістити показник на початок файлу!\n");
                    if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка*/
                    {
                        printf("Масиву структурного типу не існує!\n");
                        exit(0);
                    }
                }

                for (int i = 0; i < counter; i++) { /*перенесення елементів з масиву структурного типу до дерева*/
                    insertCheck = insertTree(BTd, &dAK[i]); /*вставлення елементу до дерева*/
                    if (insertCheck == -1) //не вдалося вставити елемент у дерево
                    {
                        printf("Не вдалося вставити елемент у дерево!\n");
                        fclose(fr); //закриття потоку роботи з файлом
                        if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка*/
                        {
                            printf("Масиву структурного типу не існує!\n");
                            exit(0);
                        }
                        exit(0);
                    }
                    else if (insertCheck == -2) /*користувач передав адресу неіснуючого дескриптору*/
                    {
                        printf("Ви передали неіснуючий дескриптор дерева!\n");
                        fclose(fr); //закриття потоку роботи з файлом
                        if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка*/
                        {
                            printf("Масиву структурного типу не існує!\n");
                            exit(0);
                        }
                        exit(0);
                    }
                }
                fclose(fr); //закриття потоку роботи з файлом
                if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                {
                    printf("Масиву структурного типу не існує!\n");
                    exit(0);
                }
                break;
            }
            case 2: {
                break;
            }
            case 3: { //заповнення дерева випадковими числами
                do {
                    printf("Введіть кількість елементів дерева:\n");
                    numberScan(counter); //зчитування пункту меню

                    if (counter < 1) {
                        printf("Введене некоректне значення! Спробуйте ще раз!\n");
                    }
                } while (counter < 1);

                printf("Введіть нижню границю для генерації випадкових чисел:\n");
                numberScan(minimum); /*зчитування введеного до консолі значення для нижньої границі задля генерації випадкових чисел*/
                do {
                    printf("Введіть верхню границю для генерації випадкових чисел:\n");
                    numberScan(maximum); /*зчитування введеного до консолі значення для верхньої границі задля генерації випадкових чисел*/

                    if (maximum < minimum) { /*перевірка на те, щоб верхня границя для генерації випадкових чисел не була меншою за нижню*/
                        printf("Верхня границя не може бути меншою за нижню!\n");
                        //exit(0);
                    }
                } while (maximum < minimum);

                DataAndKeys* dAK = (DataAndKeys*)malloc((counter) * sizeof(DataAndKeys)); //виділення пам'яті для масиву структурного типу
                if (!dAK) /*перевірка на те, чи пам'ять виділена під масив структурного типу*/
                {
                    printf("Недостатньо пам'яті для виділення її під масив\n!");
                    exit(0);
                }
                for (int i = 0; i < counter; i++) {
                    dAK[i].key = (char*)malloc(11 * sizeof(char)); /*виділення пам'яті для ключа елементу масиву структурного типу*/
                    if (!dAK[i].key) /*перевірка на те, чи виділилася пам'ять під ключ елементу масиву структурного типу*/
                    {
                        printf("Недостатньо пам'яті для виділення її під рядок\n!");
                        if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                        {
                            printf("Масиву структурного типу не існує!\n");
                            exit(0);
                        }
                        exit(0);
                    }
                    dAK[i].data = minimum + rand() % (maximum - minimum + 1); /*генерація випадкового числа*/

                    if (dAK[i].data < minimum || dAK[i].data > maximum) /*перевірка на те, чи правильно згенероване випадкове ціле число*/
                    {
                        printf("Випадкове ціле число згенеровано невірно!\n");
                        if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                        {
                            printf("Масиву структурного типу не існує!\n");
                            exit(0);
                        }
                        exit(0);
                    }
                    for (int j = 0; j < SIZE; j++) //генерація випадкового ключа
                    {
                        if (j < 7)
                        {
                            numberForLetter = 65 + rand() % (90 - 65 + 1);
                            dAK[i].key[j] = numberForLetter;
                        }
                        else
                        {
                            numberForLetter = (rand() % (9 + 1)) + 48;
                            dAK[i].key[j] = numberForLetter;
                        }
                    }
                    dAK[i].key[SIZE] = '\0'; //встановлення кінця рядка для ключа
                }

                for (int i = 0; i < counter; i++) /*перенесення елементів з масиву структурного типу до дерева*/
                {
                    if (insertTree(BTd, &dAK[i]) == -1) /*вставлення елементу до дерева та перевірка на те, чи це сталося*/
                    {
                        printf("Не вдалося вставити елемент у дерево!\n");
                        if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                        {
                            printf("Масиву структурного типу не існує!\n");
                            exit(0);
                        }
                        exit(0);
                    }
                }
                if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                {
                    printf("Масиву структурного типу не існує!\n");
                    exit(0);
                }
                break;
            }
            default: { //якщо користувач ввів некоректне значення
                printf("Ви ввели некоректне значення, спробуйте ще раз!\n");
                flag = false;
                continue;
            }
            }
        } while (!flag);

        do {
            printf("\nВиберіть тип роботи з бінарним деревом цілих чисел:\n1)Вивести \
вершину дерева;\n2)Вставити вершину у дерево;\n3)Виключити елемент з дерева\n\
4)Отримати розмір дерева та його висоту;\n5)Показ дерева на екрані;\n\
6)Записати дерево до файлу;\n7)Ввести дерево з файлу;\n8)Проходження дерева;\n9)Видалити дерево;\n\
0)Завершити програму;\n");
            numberScan(workWithBT); //зчитування пункту меню
            switch (workWithBT) {
            case 1: //виведення на екран елементу
            {
                if (!(forKey = (char*)malloc(sizeof(char) * 256))) /*виділення пам'яті для ключа, який введуть з клавіатури, і перевірка на те, чи це сталося*/
                {
                    printf("Недостатньо пам'яті для виділення її під рядок!\n");
                    exit(0);
                }
                noElementCheck = 1;

                printf("Введіть ключ(ідентифікаційний код з SIZE символів) елемента дерева, який бажаєте вивести на екран:\n");
                keyScan(forKey); //зчитування введеного з клавіатури ключа
                if (keyUsingSearch(BTd->root, forKey, &noElementCheck, &num) == 1) //пошук елементу в дереві за ключем
                {
                    printf("Елементу з таким ключем немає в дереві!\n");
                }
                free(forKey); //звільнення пам'яті для введеного з клавіатури ключа
                break;
            }
            case 2: //вставлення елемента в дерево
            {
                DataAndKeys* dAK = (DataAndKeys*)malloc(sizeof(DataAndKeys)); /*виділення пам'яті для змінної структурного типу*/

                if (!dAK) /*перевірка на те, чи пам'ять виділена під масив структурного типу*/
                {
                    printf("Недостатньо пам'яті для виділення її під масив\n!");
                    exit(0);
                }
                if (!(dAK->key = (char*)malloc(11 * sizeof(char)))) /*виділення пам'яті для ключа змінної структурного типу і перевірка на те, чи це сталося*/
                {
                    printf("Недостатньо пам'яті для виділення її під рядок!\n");
                    free(dAK); //звільнення пам'яті для змінної структурного типу
                    exit(0);
                }

                if (!(forKey = (char*)malloc(sizeof(char) * 256))) /*виділення пам'яті для ключа, який введуть з клавіатури, і перевірка на те, чи це сталося*/
                {
                    printf("Недостатньо пам'яті для виділення її під рядок!\n");
                    free(dAK->key);
                    free(dAK);
                    exit(0);
                }
                printf("Введіть ключ(ідентифікаційний код з SIZE символів), елемент з яким бажаєте вставити в дерево:\n");
                keyScan(forKey); //зчитування введеного з клавіатури ключа
                printf("Введіть ціле число, елемент з яким бажаєте вставити в дерево:\n");
                numberScan(elementNumber); /*зчитування введеного з клавіатури цілого числа*/
                dAK->data = elementNumber;
                strcpy(dAK->key, forKey);
                insertCheck = insertTree(BTd, dAK); //вставлення елементу до дерева
                if (insertCheck == -1) //не вдалося вставити елемент у дерево
                {
                    printf("Не вдалося вставити елемент у дерево!\n");
                    free(dAK->key); /*звільнення пам'яті для ключа змінної структурного типу*/
                    free(dAK); //звільнення пам'яті для змінної структурного типу
                    free(forKey); //звільнення пам'яті для введеного з клавіатури ключа
                    exit(0);
                }
                else if (insertCheck == -2) /*користувач передав адресу неіснуючого дескриптору*/
                {
                    printf("Ви передали неіснуючий дескриптор дерева!\n");
                    free(dAK->key); /*звільнення пам'яті для ключа змінної структурного типу*/
                    free(dAK); //звільнення пам'яті для змінної структурного типу
                    free(forKey); //звільнення пам'яті для введеного з клавіатури ключа
                    exit(0);
                }
                counter++;
                free(dAK->key); //звільнення пам'яті для ключа змінної структурного типу
                free(dAK); //звільнення пам'яті для змінної структурного типу
                free(forKey); //звільнення пам'яті для введеного з клавіатури ключа
                break;
            }
            case 3: //виключення елемента з дерева
            {
                if (!(forKey = (char*)malloc(sizeof(char) * 256))) /*виділення пам'яті для ключа, який введуть з клавіатури, і перевірка на те, чи це сталося*/
                {
                    printf("Недостатньо пам'яті для виділення її під рядок!\n");
                    exit(0);
                }

                printf("Введіть ключ(ідентифікаційний код з SIZE символів), елемент з яким бажаєте виключити з дерева:\n");
                keyScan(forKey); //зчитування введеного з клавіатури ключа

                noElementCheck = 1;
                keyUsingSearch(BTd->root, forKey, &noElementCheck, &num);
                if (noElementCheck == 1)
                {
                    printf("Елементу із заданим ключем немає в дереві!\n");
                    exit(0);
                }
                if (deleteElement(BTd->root, forKey, num) == NULL) //вилучення елементу з дерева
                {
                    printf("Передане дерево є виродженим!\n");
                    exit(0);
                }
                counter--;
                BTd->size--;
                free(forKey); //звільнення пам'яті для введеного з клавіатури ключа
                break;
            }
            case 4: //вивід розміру дерева та його висоти
            {
                height = 0;
                curMaxHeight = 0;
                maxHeight = 0;
                getHeight(BTd, BTd->root, &height, &curMaxHeight, &maxHeight); /*отримання висоти дерева*/
                printf("Кількість елементів у дереві:%d\nВисота дерева:%d\n", BTd->size,
                    maxHeight);
                break;
            }
            case 5: //показ дерева на екрані
            {
                if (printTree(BTd->root, nullptr, true) == -1) /*вивід до консолі дерева з перевіркою на те, чи це сталося*/
                {
                    printf("Помилка при виведенні дерева на екран!\n");
                    exit(0);
                }
                break;
            }
            case 6: //перепис дерева до файлу
            {
                printf("Введіть назву файлу у вигляді name.bin, у який бажаєте переписати дерево:\n");
                checkFilename(filename); //перевірка правильності введення назви файла
                if ((fr = fopen(filename, "w")) == NULL)
                {
                    printf("Не вдалося відкрити файл із заданою назвою!\n");
                    exit(0);
                }

                DataAndKeys* dAK = (DataAndKeys*)malloc(BTd->size * sizeof(DataAndKeys)); //виділення пам'яті для масиву структурного типу

                if (!dAK) /*перевірка на виділення пам'яті під масив структурного типу*/
                {
                    printf("Недостатньо пам'яті для виділення її під масив\n!");
                    exit(0);
                }
                count = 0;

                if (getDataAndKeys(BTd->root, dAK, &count) == -1) /*запис інформації вершин дерева до масиву структурного типу та перевірка*/
                {
                    printf("Не вдалося переписати інформацію з вершин дерева!\n");
                    if (freeStruct(dAK, count) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка*/
                    {
                        printf("Масиву структурного типу не існує!\n");
                        exit(0);
                    }
                    exit(0);
                }
                if (writeToFile(fr, count, dAK) == -1) /*переписування масиву структурного типу до файлу та перевірка*/
                {
                    printf("Не вдалося переписати масив до файлу!\n");
                    if (freeStruct(dAK, count) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка*/
                    {
                        printf("Масиву структурного типу не існує!\n");
                        exit(0);
                    }
                    exit(0);
                }
                if (freeStruct(dAK, count) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка*/
                {
                    printf("Масиву структурного типу не існує!\n");
                    exit(0);
                }
                fclose(fr); //закриття потоку роботи з файлом
                break;
            }
            case 7: //зчитування дерева з файлу
            {
                if (BTd != NULL)
                {
                    deleteTree(BTd->root); //звільнення місця під дерево
                    free(BTd); //звільнення місця під дескриптор дерева
                    BTd = createTree(); //створюємо дерево
                    if (BTd == NULL) { //перевірка на те, чи створене дерево
                        printf("Дерево не створено!");
                        return -1;
                    }
                }
                printf("Введіть назву файлу у вигляді name.bin, з якого бажаєте зчитати дані:\n");
                checkFilename(filename); //перевірка правильності введення назви файла
                if ((fr = fopen(filename, "r")) == NULL)
                {
                    printf("Не вдалося відкрити файл із заданою назвою!\n");
                    exit(0);
                }

                counter = elementCounter(fr); //підрахунок кількості елементів у файлі
                DataAndKeys* dAK = (DataAndKeys*)malloc((counter) * sizeof(DataAndKeys)); //виділення пам'яті для масиву структурного типу
                if (!dAK) /*перевірка на те, чи пам'ять виділена під масив структурного типу*/
                {
                    printf("Недостатньо пам'яті для виділення її під масив\n!");
                    exit(0);
                }
                fileReadCheck = readFromFile(fr, counter, dAK); /*перенесення елементів з файлу до масиву структурного типу*/
                if (fileReadCheck == -1) //якщо не вдалося переписати елементи з файлу
                {
                    printf("Не вдалося переписати елементи з файлу!\n");
                    if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                    {
                        printf("Масиву структурного типу не існує!\n");
                        exit(0);
                    }
                }

                else if (fileReadCheck == -2) /*якщо ідентифікаційний код елемента в файлі не відповідає розміру в SIZE елементів*/
                {
                    printf("Ідентифікаційний код елемента в файлі не відповідає розміру в SIZE елементів!\n");
                    if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                    {
                        printf("Масиву структурного типу не існує!\n");
                        exit(0);
                    }
                }
                else if (fileReadCheck == -3) /*якщо не вийшло перемістити показник на початок файлу*/
                {
                    printf("Не вийшло перемістити показник на початок файлу!\n");
                    if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                    {
                        printf("Масиву структурного типу не існує!\n");
                        exit(0);
                    }
                }
                for (int i = 0; i < counter; i++) { /*перенесення елементів з масиву структурного типу до дерева*/
                    insertCheck = insertTree(BTd, &dAK[i]); /*вставлення елементу до дерева*/
                    if (insertCheck == -1) //не вдалося вставити елемент у дерево
                    {
                        printf("Не вдалося вставити елемент у дерево!\n");
                        if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                        {
                            printf("Масиву структурного типу не існує!\n");
                            exit(0);
                        }
                        fclose(fr); //закриття потоку роботи з файлом
                        exit(0);
                    }
                    else if (insertCheck == -2) /*користувач передав адресу неіснуючого дескриптору*/
                    {
                        printf("Ви передали неіснуючий дескриптор!\n");
                        if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                        {
                            printf("Масиву структурного типу не існує!\n");
                            exit(0);
                        }
                        fclose(fr); //закриття потоку роботи з файлом
                        exit(0);
                    }
                }

                if (freeStruct(dAK, counter) == -1) /*звільнення пам'яті для масиву структурного типу і перевірка на те, чи це сталося*/
                {
                    printf("Масиву структурного типу не існує!\n");
                    exit(0);
                }
                fclose(fr); //закриття потоку роботи з файлом
                continue;
            }
            case 8: //проходження дерева
            {
                do
                {
                    printf("\nОберіть порядок проходження бінарного дерева:\n1)Прямий;\n2)Зворотній;\n3)Симетричний;\n");
                    numberScan(workWithBT); //зчитування пункту меню
                    switch (workWithBT)
                    {
                    case 1:
                    {
                        count = 0;
                        preOrder(BTd->root, &count); /*проходження дерева у прямому порядку*/
                        flag = 0;
                        break;
                    }
                    case 2:
                    {
                        count = 0;
                        postOrder(BTd->root, &count); //проходження дерева у зворотньому порядку
                        flag = 0;
                        break;
                    }
                    case 3:
                    {
                        count = 0;
                        inOrder(BTd->root, &count); //проходження дерева симетрично
                        flag = 0;
                        break;
                    }
                    default:
                    {
                        printf("Ви ввели некоректне значення, спробуйте ще раз!\n");
                        flag = 1;
                        continue;
                    }
                    }
                } while (flag != 0);
                break;
            }
            case 9: //видалення дерева
            {
                deleteTree(BTd->root); //вивільнення пам'яті для дерева
                printf("\nБінарне дерево видалено!\n");
                BTd = createTree();
                flag1 = false;
                break;
            }
            case 0: //завершення роботи
            {
                deleteTree(BTd->root); //вивільнення пам'яті для дерева
                free(BTd); //вивільнення пам'яті для дескриптора дерева
                printf("\nБінарне дерево видалено!\nРобота програми завершена!\n");
                return 0;
            }
            default: { //якщо користувач ввів некоректне значення
                printf("Ви ввели некоректне значення, спробуйте ще раз!\n");
                continue;
            }
            }
        } while (flag1);
    } while (!flag1);
}

/*
Функція створення дерева
Вхід: відсутній
Вихід:
    createTree = <адреса створеного дескриптора> - дерево створено;
               = NULL - дерево не створено
*/
BTDescriptor* createTree() {
    BTDescriptor* dsBT;
    dsBT = (BTDescriptor*)malloc(sizeof(BTDescriptor)); /*виділення пам'яті під дескриптор дерева*/
    if (!dsBT) return NULL; /*немає доступної пам'яті в купі, дескриптор не створений*/
    dsBT->root = NULL;
    dsBT->size = 0;
    return dsBT;
}

/*
Функція створення вершини дерева та ініціалізації її полів
Вхід:
    entry - адреса змінної типу DataAndKeys з полями для ініціалізації
Вихід:
    initializeNode = <адреса вершини> - створена вершина;
                   = NULL - вершину не створено або не ініціалізовано
*/
BTNode* initializeNode(const DataAndKeys* entry)
{
    BTNode* newNode = (BTNode*)malloc(sizeof(BTNode)); /*виділення пам'яті під вершину дерева*/
    if (!newNode)
    {
        return NULL;
    }
    if (!(newNode->treeData.key = (char*)malloc(11 * sizeof(char)))) /*виділення пам'яті під поле key вершини*/
    {
        return NULL;
    }
    newNode->treeData.data = entry->data;
    strcpy(newNode->treeData.key, entry->key);
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*
Рекурсивна функція знаходження мінімального елемента у дереві
Вхід:
    tree - адреса вершини дерева
Вихід:
    findSmallestElement = <адреса вершини> - вершина знайдена
                        = NULL - вершина не знайдена
*/
BTNode* findSmallestElement(BTNode* tree) {
    if (tree == NULL || tree->left == NULL)
        return tree;
    else
        return findSmallestElement(tree->left);
}

/*
Функція вилучення елемента з дерева
Вхід:
    subTree - адреса вершини дерева
    key - рядок з ключем шуканої вершини дерева
Вихід:
    deleteElement = NULL - якщо дерево вироджене
                  = <адреса вершини, яка займає місце видаленої> - якщо вузол успішно видалений
*/
BTNode* deleteElement(BTNode* subTree, char* key, int num) {
    //випадок виродженого дерева
    if (!subTree)
    {
        return subTree;
    }

    //якщо ключ шуканого елемента менший за ключ елемента, з яким ми зараз порівнюємо його
    if (num < subTree->treeData.data)
    {
        subTree->left = deleteElement(subTree->left, key, num);
    }

    //якщо ключ шуканого елемента більший за ключ елемента, з яким ми зараз порівнюємо його
    else if (num > subTree->treeData.data)
    {
        subTree->right = deleteElement(subTree->right, key, num);
    }

    //якщо ключ шуканого елемента співпадає з ключем вузла, з яким ми зараз його порівнюємо, то видаляємо цей вузол
    if (strcmp(key, subTree->treeData.key) == 0) {
        //якщо вершина з одним нащадком або без них
        if (subTree->left == NULL) {
            BTNode* temp = subTree->right;
            free(subTree);
            return temp;
        }
        else if (subTree->right == NULL) {
            BTNode* temp = subTree->left;
            free(subTree);
            return temp;
        }

        //якщо вершина має два нащадки
        BTNode* temp = findSmallestElement(subTree->right);

        strcpy(subTree->treeData.key, temp->treeData.key);
        subTree->treeData.data = temp->treeData.data;

        //видаляємо найменшого нащадка
        subTree->right = deleteElement(subTree->right, temp->treeData.key, num);
    }
    return subTree;
}

/*Функція введення значень змінних
Вхід:
    N - адреса змінної для ініціалізації
Вихід:
    numberScan = N - ініціалізована змінна
*/
int numberScan(int& N) {
    int entered = 0; //змінна для контролю введених користувачем з клавіатури символів
    do {
        do {
            entered = scanf_s("%d", &N);
            while (getchar() != '\n');
            while (entered < 1) {
                printf("Ви ввели некоректне значення, повторіть введення: ");
                entered = scanf_s("%d", &N);
                while (getchar() != '\n');
            }
        } while (entered < 1);
    } while (entered != 1);
    return N;
}

/*Функція для підрахунку кількості елементів у файлі
Вхід:
    fd - файловий дескриптор
Вихід:
    elementCounter = count - кількість елементів у файлі;
                   = -1 - якщо не переміщено показник на початок файлу
*/
int elementCounter(FILE*& fd) {
    int count = 0;

    while (!feof(fd)) {
        fscanf(fd, "%*s");
        fscanf(fd, "%*d");
        count++;
    }
    rewind(fd);
    if (ferror(fd)) {
        return -1; //не переміщено показник на початок файлу
    }
    return count;
}

/*
Функція перепису інформації вершин дерева до масиву структурного типу
Вхід:
    tree - адреса вершини дерева
    dAK - адреса масиву структурного типу
    j - адреса змінної з кількістю пройдених елементів дерева
Вихід:
    getDataAndKeys = -1 - якщо не вийшло переписати інформацію з вершин дерева
                   = 0 - якщо вийшло переписати інформацію з вершин дерева
*/
int getDataAndKeys(BTNode* tree, DataAndKeys* dAK, int* j) {
    if (tree != NULL) { /*якщо вершина існує*/
        dAK[*j].key = (char*)malloc(4 * sizeof(char));
        if (!dAK[*j].key)
        {
            return -1;
        }
        dAK[*j].data = tree->treeData.data;
        strcpy(dAK[*j].key, tree->treeData.key);
        *j = *j + 1;
        getDataAndKeys(tree->left, dAK, j); /*"пірнаємо" в ліве піддерево вузла*/
        getDataAndKeys(tree->right, dAK, j); /*"пірнаємо" в праве піддерево вузла*/
    }
    return 0;
}

/*
Функція порівняння ключів двох змінних структурного типу
Вхід:
    left - адреса змінної типу DataAndKeys
    right - адреса змінної типу DataAndKeys
Вихід:
    compareDataAndKeys = 0 - якщо ключи рівні
                       > 0 - якщо ключ першої змінної більший за ключ другої змінної
                       < 0 - якщо ключ першої змінної менший за ключ другої змінної
*/
int compareDataAndKeys(DataAndKeys* left, DataAndKeys* right)
{
    //return strcmp(left->key, right->key);
    if (left->data < right->data)
        return 1;
    else if (left->data == right->data)
        return 0;
    else
        return -1;
}

/*
Функція пошуку елементу за ключем для виведення його на екран
Вхід:
    tree - адреса вершини дерева
    key - рядок з ключем
    noElementCheck - адреса змінної для перевірки наявності елемента в дереві
Вихід:
    keyUsingSearch = noElementCheck = 0 - якщо елемент з ключем, за яким відбувався пошук, є в дереві
                                    = 1 - якщо елементу з ключем, за яким відбувався пошук, немає в дереві
*/
int keyUsingSearch(BTNode* tree, char* key, int* noElementCheck, int* num) {
    if (tree != NULL) { /*якщо вершина існує*/
        if (strcmp(key, tree->treeData.key) == 0)
        {
            printf("Елемент дерева з ключем %s:\nЦіле число, яке зберігає елемент-%d\n", key, tree->treeData.data);
            *noElementCheck = 0;
            *num = tree->treeData.data;
            return *noElementCheck;
        }
        keyUsingSearch(tree->left, key, noElementCheck, num); /*"пірнаємо" в ліве піддерево вузла*/
        keyUsingSearch(tree->right, key, noElementCheck, num); /*"пірнаємо" в праве піддерево вузла*/
    }
    return *noElementCheck;
}

/*
Функція пошуку елементу за ключем для виведення його на екран
Вхід:
    tree - адреса вершини дерева
    key - рядок з ключем
    data - адреса змінної для запису цілого числа вершини
Вихід:
    searchForData = data = 0 - якщо елементу з ключем, за яким відбувався пошук, немає в дереві
                        != 0 - ціле число вершини, якщо цей елемент в дереві з заданим ключем є
*/
int searchForData(BTNode* tree, char* key, int* data) {
    if (tree != NULL) { /*якщо вершина існує*/
        if (strcmp(key, tree->treeData.key) == 0)
        {
            printf("Елемент дерева з ключем %s:\nЦіле число, яке зберігає елемент-%d\n", key, tree->treeData.data);
            *data = tree->treeData.data;
            return *data;
        }
        searchForData(tree->left, key, data); /*"пірнаємо" в ліве піддерево вузла*/
        searchForData(tree->right, key, data); /*"пірнаємо" в праве піддерево вузла*/
    }
    return *data;
}

/*
Функція вставлення елемента в дерево
Вхід:
    dsTree - адреса дескриптора дерева
    entry - адреса змінної типу DataAndKeys з полями для ініціалізації
Вихід:
    insertTree = 0 - якщо елемент вставлено у дерево
               = -1 - якщо елемент не вставлено у дерево
               = -2 - якщо переданий неіснуючий дескриптор дерева
*/
int insertTree(BTDescriptor* dsTree, DataAndKeys* entry)
{
    if (dsTree == NULL)
    {
        return -2; //якщо переданий неіснуючий дескриптор дерева
    }
    if (dsTree->root == NULL) //перевірка на виродженість дерева
    {
        if (!(dsTree->root = initializeNode(entry)))
        {
            return -1; //не вдалося ініціалізувати вузол
        }
        ++dsTree->size;
        return 0;
    }

    BTNode* subTree = dsTree->root;

    while (subTree != NULL) /*пошук місця задля вставлення нового елементу та подальша реалізація цього*/
    {
        if (compareDataAndKeys(&subTree->treeData, entry) < 0)
        {
            if (subTree->left == NULL)
            {
                if (!(subTree->left = initializeNode(entry)))
                {
                    return -1; //не вдалося ініціалізувати вузол
                }
                ++dsTree->size;
                break;
            }
            subTree = subTree->left;
        }
        else if (compareDataAndKeys(&subTree->treeData, entry) > 0)
        {
            if (subTree->right == NULL)
            {
                if (!(subTree->right = initializeNode(entry)))
                {
                    return -1; //не вдалося ініціалізувати вузол
                }
                ++dsTree->size;
                break;
            }
            subTree = subTree->right;
        }
        else
        {
            subTree->treeData.data = entry->data;
            break;
        }
    }
    return 0;
}

/*
Функція звільнення пам'яті для масиву структурного типу
Вхід:
    dAK - адреса масиву типу DataAndKeys
    n - змінна зі значенням кількості елементів у масиві
Вихід:
    freeStruct = 0 - якщо пам'ять під масив звільнена
               = -1 - якщо масиву не існує
*/
int freeStruct(DataAndKeys* dAK, int n)
{
    if (!dAK)
    {
        return -1; //масиву структурного типу не існує
    }
    for (int i = 0; i < n; i++)
    {
        free(dAK[i].key); //звільнення пам'яті під поле key масиву dAK
    }
    free(dAK); //звільнення пам'яті під масив dAK
    return 0;
}

/*
Рекурсивна функція виводу на екран елементів дерева
Вхід:
    root - адреса вершини дерева
    prev - адреса рядку для зображення з'єднань елементів дерева
    isLeft - змінна для визначення існування лівого нащадку
Вихід:
    printTree = 0 - якщо дерево виведене на екран
              = -1 - якщо не вийшло вивести дерево на екран
*/
int printTree(BTNode* root, Trunk* prev, bool isLeft)
{
    if (root == nullptr) {
        return 0;
    }

    char prev_str[] = "    ";
    Trunk* trunk = NULL;
    if (!(trunk = (Trunk*)malloc(sizeof(Trunk))))
    {
        return -1; //недостатньо пам'яті для виділення її під змінну типу Trunk
    }
    trunk->prev = prev;
    trunk->str = prev_str;

    printTree(root->right, trunk, false); /*"пірнаємо" в праве піддерево вузла*/

    if (!prev) {
        //strcpy(trunk->str, "----");
        strcpy(trunk->str, "    ");
    }
    else if (isLeft)
    {
        /*strcpy(trunk->str, ".---");
        strcpy(prev_str, "   |");*/
        strcpy(trunk->str, "    ");
        strcpy(prev_str, "    ");
    }
    else {
        /*strcpy(trunk->str, "`---");*/
        strcpy(trunk->str, "    ");
        prev->str = prev_str;
    }

    showTrunks(trunk); //виводимо на екран з'єднання елементів дерева
 /*   printf("  %s\n", root->treeData.key);*/
    printf("  %s", root->treeData.key);
    printf(" %d\n", root->treeData.data);

    if (prev) {
        prev->str = prev_str;
    }
    /*strcpy(trunk->str, "   |");*/
    strcpy(trunk->str, "    ");

    printTree(root->left, trunk, true);  /*"пірнаємо" у ліве піддерево вузла*/
    free(trunk); //звільняємо пам'ять під змінну типу Trunk
    return 0;
};

/*
Функція для зчитування даних з файлу і запису їх до комірок масиву типу DataAndKeys
Вхід:
    fp - файловий дескриптор
    size - змінна з кількістю елементів у файлі
    dAK - адреса масиву типу DataAndKeys
Вихід:
    readFromFile = -1 - якщо не вдалося переписати елементи з файлу
                 = -2 - якщо ідентифікаційний код у файлі не відповідає розміру в 10
    елементів
                 = -3 - якщо не вийшло перемістити показник на початок файлу
                 = 0 - якщо елементи з файлу успішно переписані
*/
int readFromFile(FILE* fp, int size, DataAndKeys* dAK)
{
    char* data = (char*)malloc(102 * sizeof(char)); /*виділення пам'яті під рядок для перепису цілого числа з файлу до нього*/
    if (!data)
    {
        return -1;
    }
    for (int i = 0; i < size; i++) { /*перепис вмісту файлу до масиву структурного типу dAK*/
        dAK[i].key = (char*)malloc(256 * sizeof(char)); /*виділення пам'яті під рядок для перепису ключа з файлу до нього*/
        if (!dAK[i].key)
        {
            free(data);
            return -1;
        }
        fscanf(fp, "%s", dAK[i].key);
        if (strlen(dAK[i].key) > SIZE)
        {
            free(data);
            for (int j = 0; j < i; j++)
            {
                free(dAK[i].key);
            }
            return -2;
        }
        if (strlen(dAK[i].key) < SIZE)
        {
            free(data);
            for (int j = 0; j < i; j++)
            {
                free(dAK[i].key);
            }
            return -2;
        }
        fscanf(fp, "%s", data);
        dAK[i].data = 0;

        for (int j = strlen(data) - 1, g = 0; j >= 0; j--, g++)
        {
            if (data[j] == '-')
            {
                dAK[i].data = dAK[i].data * (-1);
            }
            else
            {
                dAK[i].data = (int)(dAK[i].data + (data[j] - 48) * (int)pow(10, g));
            }
        }
    }
    rewind(fp);
    if (ferror(fp)) {
        free(data); //звільнення пам'яті під масив data
        for (int i = 0; i < size; i++)
        {
            free(dAK[i].key);
        }
        return -3;
    }
    free(data); //звільнення пам'яті під масив data
    return 0;
}

/*
Функція запису елементів масиву типу DataAndKeys до файлу
Вхід:
    fp - файловий дескриптор
    size - змінна з кількістю елементів у файлі
    dAK - адреса масиву типу DataAndKeys
Вихід:
    writeToFile = -1 - якщо не вдалося переписати масив до файлу
                = 0 - якщо масив успішно переписаний до файлу
*/
int writeToFile(FILE* fp, int size, DataAndKeys* dAK)
{
    for (int i = 0; i < size; i++) //запис елементів до файлу
    {
        if (!fprintf(fp, "%s ", dAK[i].key))
        {
            return -1;
        }

        if (i == size - 1)
        {
            if (!fprintf(fp, "%d", dAK[i].data))
            {
                return -1;
            }
        }
        else
        {
            if (!fprintf(fp, "%d\n", dAK[i].data))
            {
                return -1;
            }
        }
    }
    return 0;
}

/*
Функція для перевірки правильності введення назви файлу
Вхід:
    filename - рядок з введеною користувачем назви файлу
Вихід: відсутній
*/
void checkFilename(char filename[]) {
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
                if (filename[i + 1] != 'b' || filename[i + 2] != 'i' ||
                    filename[i + 3] != 'n' || filename[i + 4] != '\n')
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

/*
Функція визначення висоти дерева
Вхід:
    tree - адреса вершини дерева
    height - адреса змінної з висотою елементу, який наразі проходиться
    curMaxHeight - адреса змінної з поточною максимальною висотою дерева
    maxHeight - адреса змінної з максимальною висотою дерева
Вихід: відсутній
*/
void getHeight(BTDescriptor* dsTree, BTNode* tree, int* height, int* curMaxHeight, int* maxHeight)
{
    if (dsTree == NULL)
    {
        return;
    }

    if (tree != NULL) { /*якщо вершина існує*/
        *height = *height + 1;
        getHeight(dsTree, tree->left, height, curMaxHeight, maxHeight); /*"пірнаємо" в ліве піддерево вузла*/
        *height = *height + 1;
        getHeight(dsTree, tree->right, height, curMaxHeight, maxHeight); /*"пірнаємо" в праве піддерево вузла*/
    }
    else
    {
        *curMaxHeight = *height;
        if (*curMaxHeight > *maxHeight)
        {
            *maxHeight = *curMaxHeight;
        }
    }
    *height = *height - 1;
    return;
}

/*
Функція проходження дерева у прямому порядку
Вхід:
    tree - адреса вершини дерева
    j - адреса змінної з кількістю пройдених елементів дерева
Вихід: відсутній
*/
void preOrder(BTNode* tree, int* j) {
    if (tree != NULL) { /*якщо вершина існує*/
        *j = *j + 1;
        printf("\nВершина №%d:\nЦіле число, яке зберігає вершина-%d\nКлюч вершини-%s\n", *j, tree->treeData.data, tree->treeData.key); /*обробка даних навершині дерева*/
        preOrder(tree->right, j); /*"пірнаємо" в ліве піддерево вузла*/
        preOrder(tree->left, j); /*"пірнаємо" в праве піддерево вузла*/
    }
    return;
}

/*
Функція проходження дерева у зворотньому порядку
Вхід:
    tree - адреса вершини дерева
    j - адреса змінної з кількістю пройдених елементів дерева
Вихід: відсутній
*/
void postOrder(BTNode* tree, int* j) {
    if (tree != NULL) { /*якщо вершина існує*/
        postOrder(tree->right, j); /*"пірнаємо" в ліве піддерево вузла*/
        postOrder(tree->left, j); /*"пірнаємо" в праве піддерево вузла*/
        *j = *j + 1;
        printf("\nВершина №%d:\nЦіле число, яке зберігає вершина-%d\nКлюч вершини-%s\n", *j, tree->treeData.data, tree->treeData.key); /*обробка даних на вершині дерева*/
    }
    return;
}

/*
Функція симетричного проходження дерева
Вхід:
    tree - адреса вершини дерева
    j - адреса змінної з кількістю пройдених елементів дерева
Вихід: відсутній
*/
void inOrder(BTNode* tree, int* j) {
    if (tree != NULL) { /*якщо вершина існує*/
        inOrder(tree->left, j); /*"пірнаємо" в ліве піддерево вузла*/
        *j = *j + 1;
        printf("\nВершина №%d:\nЦіле число, яке зберігає вершина-%d\nКлюч вершини-%s\n", *j, tree->treeData.data, tree->treeData.key); /*обробка даних на вершині дерева*/
        inOrder(tree->right, j); /*"пірнаємо" в праве піддерево вузла*/
    }
    return;
}

/*
Функція введення коректного ключа
Вхід:
    key - рядок з ключем, який користувач ввів з клавіатури
Вихід: відсутній
*/
void keyScan(char* key)
{
    int entered = 0; //змінна для контролю введених користувачем з клавіатури символів
    int lCheck = 1; /*змінна для контролю кількості введених користувачем з клавіатури символів*/
    do {
        do {
            entered = scanf("%s", key);
            while (getchar() != '\n');
            while (entered < 1) {
                printf("Ви ввели некоректний ключ, повторіть введення: ");
                entered = scanf("%s", key);
                while (getchar() != '\n');
            }
        } while (entered < 1);

        if (strlen(key) < SIZE)
        {
            printf("Ви ввели ключ з меншою кількістю символів, ніж потрібно, повторіть введення:\n");
            lCheck = 0;
        }
        else if (strlen(key) > SIZE)
        {
            printf("Ви ввели ключ з більшою кількістю символів, ніж потрібно, повторіть введення:\n");
            lCheck = 0;
        }
        else
        {
            lCheck = 1;
        }
    } while (entered != 1 || lCheck == 0);
}

/*
Рекурсивна функція виводу на екран з'єднань елементів дерева
Вхід:
    trunk - адреса змінної типу Trunk
Вихід: відсутній
*/
void showTrunks(const Trunk* trunk)
{
    if (trunk == nullptr) {
        return;
    }

    showTrunks(trunk->prev);
    printf("%s", trunk->str);
}

/*
Функція видалення дерева
Вхід:
    tree - адреса вершини дерева
Вихід: відсутній
*/
void deleteTree(BTNode* tree) {
    if (tree != NULL) { /*якщо вершина існує*/
        deleteTree(tree->left); /*"пірнаємо" в ліве піддерево вузла*/
        deleteTree(tree->right); /*"пірнаємо"в праве піддерево вузла*/
        free(tree->treeData.key); //звільнення пам'яті під поле key вузла
        free(tree); //звільнення пам'яті під вузол
    }
    return;
}