#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include <iostream>
#include "Set.h"
using namespace std;
int Compare(Set set1, Set set2);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Set set1("22holymoly11", 12);
	cout << "Множина до видалення заданого елементу з неї : ";
	if (set1.Print() == 0)
	{
		return 0;
	}
	cout << endl;
	set1 - '2';
	cout << "Множина після видалення заданого елементу з неї: ";
	set1.Print();
	cout << endl;

	Set set2(set1);
	if (Compare(set2, set1) == -1)
	{
		return -1;
	}

	set2 - '1';
	if (Compare(set2, set1) == -1)
	{
		return -1;
	}

	set2 - 'l';
	if (Compare(set1, set2) == -1)
	{
		return -1;
	}

	cout << "\n\nПерша підмножина для утворення множини, що буде результатом перетину її з другою: ";
	set1.Print();
	cout << endl;
	cout << "Друга підмножина для утворення множини, що буде результатом перетину її з першою: ";
	set2.Print();
	cout << endl;
	set1* set2;
	cout << "Множина, що є перетином двох підмножин: ";
	set1.Print();
	cout << endl;

	Set setWithoutData;
	if (Compare(setWithoutData, set1) == -1)
	{
		return -1;
	}

	Set set3("1bla3bla2");
	cout << "Множина до зміни її змісту: ";
	set3.Print();
	cout << endl;
	set3.SetData("thirdsetsetthree", 16);
	cout << "Множина після зміни її змісту: ";
	set3.Print();
	cout << endl << endl;

	cout << "Множина до встановлення меншої її поточної довжини за теперішню та видалення зайвих елементів: ";
	set3.Print();
	cout << endl;
	cout << "Поточна довжина множини до її зміни на меншу: " << set3.GetCurrentSize() << endl;
	set3.SetCurrentSize(set3.GetCurrentSize() - 1);
	cout << "Множина після встановлення меншої її поточної довжини за теперішню та видалення зайвих елементів: ";
	set3.Print();
	cout << endl;
	cout << "Поточна довжина множини після її зміни на меншу: " << set3.GetCurrentSize() << endl << endl;

	cout << "Множина до встановлення більшої її поточної довжини(але не більшої за максимальну ємність) за теперішню: ";
	set3.Print();
	cout << endl;
	cout << "Поточна довжина множини до її зміни на більшу: " << set3.GetCurrentSize() << endl;
	set3.SetCurrentSize(set3.GetCurrentSize() + 3);
	cout << "Множина після встановлення більшої її поточної довжини(але не більшої за максимальну ємність) за теперішню: ";
	set3.Print();
	cout << endl;
	cout << "Поточна довжина множини після її зміни на більшу: " << set3.GetCurrentSize() << endl << endl;

	set3.SetData("1234567890-=qwertyuiop[]asdfghjkl;,", 35);
	cout << "Множина, поточна ємність якої дорівнює максимальній, до зміни maxSize: ";
	set3.Print();
	cout << endl;
	cout << "Максимальна довжина множини до її зміни на більшу: " << set3.GetMaxSize() << endl;
	set3.SetCurrentSize(set3.GetMaxSize() + 3);
	cout << "Максимальна довжина множини після її зміни на більшу: " << set3.GetCurrentSize() << endl;

	set3.SetData("1234567890-=qwertyuiop[]asdfghjkl;,про");
	cout << "Множина, поточна ємність якої дорівнює максимальній, після зміни maxSize: ";
	set3.Print();
	cout << endl << endl;

	Set set4("letscheckgetters", 16);
	int currentSizeSet4 = set4.GetCurrentSize();
	int maxSizeSet4 = set4.GetMaxSize();
	char* dataSet4 = set4.GetData();
	cout << "Множина, яка зберігається в полі класу: {";
	for (int i = 0; i < currentSizeSet4; i++)
	{
		if (i == currentSizeSet4 - 1)
		{
			cout << dataSet4[i];
		}
		else
		{
			cout << dataSet4[i] << ", ";
		}
	}
	cout << "}" << endl;
	cout << "Максимальна кількість елементів, яку можна вмістити у рядок: " << maxSizeSet4 << endl;
	cout << "Кількість елементів у рядку на даний момент: " << currentSizeSet4 << endl << endl;

	Set set5("bruhiamtired");
	cout << "Об'єкт класу, копія якого буде створена:" << endl;
	cout << "Множина, яка зберігається в полі класу: ";
	set5.Print();
	cout << endl;
	cout << "Максимальна кількість елементів, яку можна вмістити у рядок: " << set5.GetMaxSize() << endl;
	cout << "Кількість елементів у рядку на даний момент: " << set5.GetCurrentSize() << endl << endl;
	Set set6 = set5;
	cout << "Копія, утворена за допомогою оператора присвоювання:" << endl;
	cout << "Множина, яка зберігається в полі класу: ";
	set6.Print();
	cout << endl;
	cout << "Максимальна кількість елементів, яку можна вмістити у рядок: " << set6.GetMaxSize() << endl;
	cout << "Кількість елементів у рядку на даний момент: " << set6.GetCurrentSize() << endl << endl;
}

/*
Функція Compare для порівняння ємностей двох множин і виводу результату до консолі
Вхід:
set1-перший об'єкт класу, ємність множини якого потрібно порівняти, передача за значенням
set2-другий об'єкт класу, ємність множини якого потрібно порівняти, передача за значенням
Вихід:
-1-якщо одна з множин для порівняння не існує
0-при успішному виконанні функції, якщо перша множина не менша за другу
1-при успішному виконанні функції, якщо перша множина менша за другу
*/
int Compare(Set set1, Set set2)
{
	cout << "Перша множина для порівняння: ";
	set1.Print();
	cout << endl;
	cout << "Друга множина для порівняння: ";
	set2.Print();
	cout << endl;
	if (set1 < set2 == -2)
	{
		cout << "Одна з множин для порівняння не існує!" << endl;
		return -1;
	}
	else if (set1 < set2 == 1)
	{
		cout << "Множина ";
		set1.Print();
		cout << " менша за множину ";
		set2.Print();
		cout << endl;
		return 1;
	}
	else
	{
		cout << "Множина ";
		set1.Print();
		cout << " не менша за множину ";
		set2.Print();
		cout << endl;
		return 0;
	}
}
