#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "locale.h"
#include "string.h"
#include "windows.h"

/* структура з даними службовця */
struct tWorker {
	char surname[30];
	char name[30];
	int age;
};

/* структура вузла стека */
struct tStackNode { /* структура вузла стека */
	struct tWorker worker; /* дані про службовця */
	tStackNode* next; /* покажчик на наступний елемент стека */
};

/* формат дескриптора стека */
struct tSD {
	tStackNode* top; /* покажчик вершини стека */
	int size; /* поточний розмір стека (в елементах) */
};

/* Прототипи функцій */
tSD* CreateStack(void);
int PushStack(tSD* sd, const tWorker* worker);
int PopStack(tSD* sd, tWorker* worker);
int DestroyStack(tSD* sd);
void Input(tWorker* worker);
void Print(const tWorker* worker);
int Enter(int& N);
void CheckFilename(char filename[]);
int GetWorker(char line[], tWorker* worker);

int main() {
	tSD* sd = NULL;
	FILE* fr = NULL; //файловий дескриптор для встановлення потоку з файлом
	tWorker worker; //змінна структурного типу для передачі даних в стек
	int workWithStack; //змінна пункту меню
	char filename[50]; //рядок з назвою файлу
	char string[50]; //масив для переписування рядків по одному з файлу
	bool flag = true;

	SetConsoleCP(1251); //підключення кирилиці
	SetConsoleOutputCP(1251);

	for (;;) {
		printf("1)Створити новий файл;\n2)Заповнити стек з існуючого файлу (прізвище ім'я вік);\n3)Створити новий стек;\n4)Додати елемент у стек;\n5)Прочитати стек;\n6)Показати зміст стека і його розмір;\n7)Заповнити файл із стеку;\n0)Завершити роботу;\n");
		Enter(workWithStack); //зчитування пункту меню

		switch (workWithStack) {
		case 1: { // створення нового файлу для стека
			if (sd == NULL) {
				printf("Cтек не існує!\n");
				continue;
			}

			printf("Введіть назву файлу у вигляді name.txt:\n");
			CheckFilename(filename); //перевірка правильності введення назви файла

			if ((fr = fopen(filename, "w")) == NULL)
			{
				printf("Виникла помилка при відкритті файлу %s! \n", filename);
				exit(0);
			}

			printf("\nСтворено новий файл для стеку\n");

			fclose(fr);

			if (ferror(fr)) {
				printf("Помилка при закритті файлу %s", filename);
				return 1;
			}

			break;
		}
		case 2: { // заповнення стеку з існуючого файлу
			if (sd == NULL) {
				printf("Cтек не існує\n!");
				continue;
			}

			printf("Введіть назву файлу у вигляді name.txt, з якого бажаєте зчитати дані:\n");
			CheckFilename(filename); //перевірка правильності введення назви файла

			if ((fr = fopen(filename, "r")) == NULL)
			{
				printf("Виникла помилка при відкритті файлу %s! \n", filename);
				exit(0);
			}

			while (fgets(string, 50, fr)) {
				if (GetWorker(string, &worker) == 1) { //заносимо дані з файлу до структури з перевіркою
					printf("Елементи повинні бути у вигляді <прізвище ім'я вік>!");
					return 2;
				}

				int check = PushStack(sd, &worker); //розміщуємо в стеку

				if (check == -1) {
					printf("Не вистачає пам'яті (стек повний)!");
					return 1;
				}
			}

			printf("\nСтек заповнено з існуючого файлу\n");

			fclose(fr);

			if (ferror(fr)) {
				printf("Помилка при закритті файлу %s", filename);
				return 1;
			}

			if ((fr = fopen(filename, "a")) == NULL)
			{
				printf("Виникла помилка при відкритті файлу %s! \n", filename);
				exit(0);
			}

			break;
		}
		case 3: { // створення стеку
			if (sd) {
				DestroyStack(sd);
				//continue;
			}

			sd = CreateStack(); //створюємо стек

			if (sd == NULL) {
				printf("Cтек не створений!");
				return 1;
			}

			printf("Стек створено!\n");

			break;
		}
		case 4: { // додання елементу у стек
			if (sd == NULL) {
				printf("Cтек не існує!\n");
				continue;
			}

			Input(&worker); //введення даних в структуку

			int check = PushStack(sd, &worker); //додання структури до стека з перевіркою
			if (check == -1) {
				printf("\nНе вистачає пам'яті (стек повний)!\n");
				break;
			}

			break;
		}
		case 5: { // прочитати стек
			if (sd == NULL) {
				printf("Cтек не існує!\n");
				continue;
			}

			int check = PopStack(sd, &worker);
			if (check == -3) {
				printf("\nCтек порожній!\n");
				break;
			}

			Print(&worker); //виведення видаленого масиву на консоль
			printf("Елемент видалено!\n\n");

			break;
		}
		case 6: { // показати зміст стека та його розмір
			if (sd == NULL) {
				printf("Cтек не існує!\n");
				continue;
			}

			tWorker* helpWorker = (tWorker*)calloc(sd->size, sizeof(tWorker)); //ініциалізуємо динамічний допоміжний масив
			if (!helpWorker) {
				printf("Не вистачає пам'яті!\n");
				return 1;
			}

			int currentSize = sd->size;
			for (int i = sd->size - 1; i >= 0; i--) { //видалення та перенесення даних в допоміжний масив
				PopStack(sd, &helpWorker[i]);
			}

			for (int i = 0; i < currentSize; i++) { //перенесення даних в стек та файл
				PushStack(sd, &helpWorker[i]);
				if (!fprintf(stdout, "%s %s %d\n", helpWorker[i].surname, helpWorker[i].name, helpWorker[i].age))
				{
					printf("Виникла помилка запису структури у файл!\n");
					return 1;
				}
			}
			free(helpWorker);

			printf("\nПоточний розмір стеку (в елементах) - %d \n\n", sd->size);

			break;
		}
		case 7: { // заповнення файлу з стеку
			if (sd == NULL) {
				printf("Cтек не існує!\n");
				continue;
			}
			printf("Введіть назву файлу у вигляді name.txt, в який бажаєте записати стек:\n");
			CheckFilename(filename); //перевірка правильності введення назви файла
			if ((fr = fopen(filename, "w")) == NULL)
			{
				printf("Виникла помилка при відкритті файлу %s! \n", filename);
				exit(0);
			}

			tWorker* helpWorker = (tWorker*)calloc(sd->size, sizeof(tWorker)); //ініциалізуємо динамічний допоміжний масив
			if (!helpWorker) {
				printf("Не вистачає пам'яті!\n");
				return 1;
			}

			int currentSize = sd->size;
			for (int i = sd->size - 1; i >= 0; i--) { //видалення та переносення даних в допоміжний масив
				PopStack(sd, &helpWorker[i]);
			}

			for (int i = 0; i < currentSize; i++) { //перенесення даних в стек та файл
				PushStack(sd, &helpWorker[i]);
				if (!fprintf(fr, "%s %s %d\n", helpWorker[i].surname, helpWorker[i].name, helpWorker[i].age))
				{
					printf("Виникла помилка запису структури у файл!\n");
					return 1;
				}
			}

			free(helpWorker);

			fclose(fr);

			if (ferror(fr)) {
				printf("Помилка при закритті файлу %s", filename);
				return 1;
			}

			break;
		}
		case 0: { // завершення роботи
			if (DestroyStack(sd) == -2)
				printf("\nСтек не існує!\n");
			if (DestroyStack(sd) == 0)
				printf("\nСтек видалено!\n");
			printf("\nРобота програми завершена!\n");
			return 0;

			break;
		}
		default: {
			printf("Ви ввели некоректне значення, спробуйте ще раз!\n");
			flag = false;
			continue;
		}
		}
	} while (!flag);
}
/*Функція створення стека
Вхід:
Відсутній
Вихід:
Адреса на створений стек
*/
tSD* CreateStack(void) {
	tSD* sd = (tSD*)malloc(sizeof(tSD));
	if (!sd)
		return NULL;   /* стек не створений */

	else { /* стек створений */
		sd->top = NULL; /* ініціалізація вершини стека */
		sd->size = 0; /* ініціалізація розміру стека */
		return sd;
	}
}

/*Функція включення елемента до стека
Вхід:
Адреса на стек
Елемент, який буде доданий до стека
Вихід:
Ціле число, як результат виконання функції
*/
int PushStack(tSD* sd, const tWorker* worker) {
	tStackNode* sn; /* покажчик на новий елемент */
	if (!sd) /* стек не існує! */
		return -2;
	sn = (tStackNode*)malloc(sizeof(tStackNode)); /* створення нового вузла списку */
	if (!sn) /* не вистачає пам'яті (стек повний) */
		return -1;
	sn->worker = *worker; /* занесення даних про службовця в стек */
	sn->next = sd->top; /* встановлення покажчика на наступний елемент у новому вузлі */

	sd->size++; /* зміна поточного розміру стека */
	sd->top = sn; /* встановлення покажчика на вершину стека в дескрипторі */

	return 0;
}

/*Функція вибірки елемента зі стека
Вхід:
Адреса на стек
Змінна, в яку запишеться видалений елемент
Вихід:
Ціле число, як результат виконання функції
*/
int PopStack(tSD* sd, tWorker* worker) {
	tStackNode* pDel; /* адреса "виштовхуємого" вузла */

	if (!sd) /* стек не існує */
		return -2;

	if (!sd->top) /* стек вже порожній (underflow) */
		return -3;

	else { /* вибірка елемента з-верхівки стека */
		*worker = sd->top->worker; /* передаються дані з елемента */
		pDel = sd->top; /* зберігається адреса "виштовхуємого" елемента */
		sd->top = sd->top->next; // вершиною стека стає наступний елемент
		sd->size--; /* зміна поточного розміру стека */
		free(pDel); /* звільняється пам'ять "виштовхнутого" елемента */

		return 0;
	}
}

/*Функція видалення стека
Вхід:
Адреса на стек, який буде видалений
Вихід:
Ціле число, як результат виконання функції
*/
int DestroyStack(tSD* sd) {
	tStackNode* pDel; /* адреса тимчасового елемента стека */

	if (!sd) {  /* стек не існує */
		return -2;
	}

	/* якщо стек не порожній - спершу слід видалити всі елементи! */
	while (sd->top) { /* обхід елементів стека */
		pDel = sd->top; /* збереження адреси вершини стека для видалення */
		sd->top = sd->top->next; /* "обрізання" верхівки стека */
		free(pDel); /* видалення колишньої верхівки стека*/
	}
	free(sd); /* звільняється пам'ять дескриптора стека */

	return 0;
}

/*Функція введеня значень до стека з перевіркою
Вхід:
Змінна структурного типу
Вихід:
Відсутній
*/
void Input(tWorker* worker) {
	do {
		printf("Прізвище: ");
		gets_s(worker->surname);

		if (worker->surname[0] == '\n')
		{
			printf("Ви нічого не ввели, спробуйте ще раз!\n");
		}

		if (strlen(worker->surname) > 20) {
			printf("Не вистачає пам'яті, спробуйте ще раз!\n");
		}

	} while (worker->surname[0] == '\n' && strlen(worker->surname) > 20);

	do {
		printf("Ім'я: ");
		gets_s(worker->name);

		if (worker->name[0] == '\n')
		{
			printf("Ви нічого не ввели, спробуйте ще раз!\n");
		}

		if (strlen(worker->name) > 20) {
			printf("Не вистачає пам'яті, спробуйте ще раз!\n");
		}

	} while (worker->name[0] == '\n' && strlen(worker->name) > 20);

	printf("Вік: ");
	Enter(worker->age);
}

/*Функція виведення стека на екран
Вхід:
Змінна структурного типу
Вихід:
Відсутній
*/
void Print(const tWorker* worker) {
	printf("Прізвище: %s\nІм'я: %s\nВік: %d\n", worker->surname, worker->name, worker->age);
}

/*Функція введення значень змінних
Вхід:
Змінна для заповнення, передача за посиланням
Вихід:
Змінна з записаним числом
*/
int Enter(int& N) {
	while (scanf_s("%d%*c", &N) < 1) {
		printf("Ви ввели некоректне значення, повторіть введення: ");
		getchar();
	}
	return N;
}

/*Функція для перевірки правильності введення назви файлів
Вхід:
Масив, у якому записана назва файлу, яку ввів користувач filename[]
Вихід:
Відсутній
*/
void CheckFilename(char filename[]) {
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

/*Функція занесення значень зі строки в структуру з перевіркою
Вхід:
Рядок, з якого будуть братися дані
Змінна структурного типу, в яку будуть занесені дані
Вихід:
Ціле число, як результат виконання функції
*/
int GetWorker(char line[], tWorker* worker) {
	int w = 0;
	int k = 0;

	SetConsoleCP(1251); //підключення кирилиці
	SetConsoleOutputCP(1251);

	for (int i = w;; i++) {
		if (line[i] >= 'А' && line[i] <= 'Я' || line[i] >= 'а' && line[i] <= 'я') {
			w = i;
			for (int j = i;; j++) {
				if (line[j] == ' ') {
					w++;
					break;
				}
				else {
					worker->surname[k] = line[i];
					i++;
					k++;
					w++;
				}
			}
			break;
		}
		else
			return 1;
	}

	if (worker->surname[k] != '\0') {
		worker->surname[k] = '\0';
	}

	k = 0;

	for (int i = w;; i++) {
		if (line[i] >= 'А' && line[i] <= 'Я' || line[i] >= 'а' && line[i] <= 'я') {
			w = i;
			for (int j = i;; j++) {
				if (line[j] == ' ') {
					w++;
					break;
				}
				else {
					worker->name[k] = line[i];
					i++;
					k++;
					w++;
				}
			}
			break;
		}
		else
			return 1;
	}

	if (worker->name[k] != '\0') {
		worker->name[k] = '\0';
	}

	char age[20];
	k = 0;
	int g = 0;

	for (int i = w;; i++) {
		if (line[i] >= '0' && line[i] <= '9') {
			w = i;
			for (int j = i;; j++) {
				if (line[j] == '\n' || line[j] == '\0') {
					break;
				}
				else {
					age[k] = line[i];
					i++;
					k++;
					w = w + 1;
				}
			}
			break;
		}
	}

	if (age[k] != '\0') {
		age[k] = '\0';
	}

	int intYear = 0;

	for (int i = strlen(age) - 1; i >= 0; i--) {
		intYear = intYear + (age[i] - 48) * pow(10, g);
		g++;
	}

	worker->age = intYear;

	return 0;
}