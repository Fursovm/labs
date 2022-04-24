#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include <iostream>
#include "MyClass.h"
using namespace std;
int Compare(MyClass MyClass1, MyClass MyClass2);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MyClass MyClass1("Hello, World!", 13);
	cout << "Множина до видалення заданого елементу з неї : ";
	if (MyClass1.Print() == 0)
	{
		return 0;
	}
	cout << endl;
	MyClass1 - ',';
	cout << "Множина після видалення заданого елементу з неї: ";
	MyClass1.Print();
	cout << endl;

	MyClass MyClass2(MyClass1);
	if (Compare(MyClass2, MyClass1) == -1)
	{
		return -1;
	}

	MyClass2 - '!';
	if (Compare(MyClass2, MyClass1) == -1)
	{
		return -1;
	}

	MyClass2 - 'l';
	if (Compare(MyClass1, MyClass2) == -1)
	{
		return -1;
	}

	cout << "\n\nПерша підмножина для утворення множини, що буде результатом перетину її з другою: ";
	MyClass1.Print();
	cout << endl;
	cout << "Друга підмножина для утворення множини, що буде результатом перетину її з першою: ";
	MyClass2.Print();
	cout << endl;
	MyClass1* MyClass2;
	cout << "Множина, що є перетином двох підмножин: ";
	MyClass1.Print();
	cout << endl;

	MyClass classWithoutData;
	if (Compare(classWithoutData, MyClass1) == -1)
	{
		return -1;
	}

	MyClass MyClass3("three3two2one1");
	cout << "Множина до зміни її змісту: ";
	MyClass3.Print();
	cout << endl;
	MyClass3.SetData("iloveyou", 8);
	cout << "Множина після зміни її змісту: ";
	MyClass3.Print();
	cout << endl << endl;

	cout << "Множина до встановлення меншої її поточної довжини за теперішню та видалення зайвих елементів: ";
	MyClass3.Print();
	cout << endl;
	cout << "Поточна довжина множини до її зміни на меншу: " << MyClass3.GetCurrentSize() << endl;
	MyClass3.SetCurrentSize(MyClass3.GetCurrentSize() - 1);
	cout << "Множина після встановлення меншої її поточної довжини за теперішню та видалення зайвих елементів: ";
	MyClass3.Print();
	cout << endl;
	cout << "Поточна довжина множини після її зміни на меншу: " << MyClass3.GetCurrentSize() << endl << endl;

	cout << "Множина до встановлення більшої її поточної довжини(але не більшої за максимальну ємність) за теперішню: ";
	MyClass3.Print();
	cout << endl;
	cout << "Поточна довжина множини до її зміни на більшу: " << MyClass3.GetCurrentSize() << endl;
	MyClass3.SetCurrentSize(MyClass3.GetCurrentSize() + 3);
	cout << "Множина після встановлення більшої її поточної довжини(але не більшої за максимальну ємність) за теперішню: ";
	MyClass3.Print();
	cout << endl;
	cout << "Поточна довжина множини після її зміни на більшу: " << MyClass3.GetCurrentSize() << endl << endl;

	MyClass3.SetData("hellomynameismacim18yearsold0987654", 35);
	cout << "Множина, поточна ємність якої дорівнює максимальній, до зміни maxSize: ";
	MyClass3.Print();
	cout << endl;
	cout << "Максимальна довжина множини до її зміни на більшу: " << MyClass3.GetMaxSize() << endl;
	MyClass3.SetCurrentSize(MyClass3.GetMaxSize() + 3);
	cout << "Максимальна довжина множини після її зміни на більшу: " << MyClass3.GetCurrentSize() << endl;

	MyClass3.SetData("hellomynameismacim18yearsold098765yutr");
	cout << "Множина, поточна ємність якої дорівнює максимальній, після зміни maxSize: ";
	MyClass3.Print();
	cout << endl << endl;

	MyClass MyClass4("getterschecker", 14);
	int currentSize4 = MyClass4.GetCurrentSize();
	int maxSize4 = MyClass4.GetMaxSize();
	char* data4 = MyClass4.GetData();
	cout << "Множина, яка зберігається в полі класу: {";
	for (int i = 0; i < currentSize4; i++)
	{
		if (i == currentSize4 - 1)
		{
			cout << data4[i];
		}
		else
		{
			cout << data4[i] << ", ";
		}
	}
	cout << "}" << endl;
	cout << "Максимальна кількість елементів, яку можна вмістити у рядок: " << maxSize4 << endl;
	cout << "Кількість елементів у рядку на даний момент: " << currentSize4 << endl << endl;

	MyClass MyClass5("bruhiamtired");
	cout << "Об'єкт класу, копія якого буде створена:" << endl;
	cout << "Множина, яка зберігається в полі класу: ";
	MyClass5.Print();
	cout << endl;
	cout << "Максимальна кількість елементів, яку можна вмістити у рядок: " << MyClass5.GetMaxSize() << endl;
	cout << "Кількість елементів у рядку на даний момент: " << MyClass5.GetCurrentSize() << endl << endl;
	MyClass MyClass6 = MyClass5;
	cout << "Копія, утворена за допомогою оператора присвоювання:" << endl;
	cout << "Множина, яка зберігається в полі класу: ";
	MyClass6.Print();
	cout << endl;
	cout << "Максимальна кількість елементів, яку можна вмістити у рядок: " << MyClass6.GetMaxSize() << endl;
	cout << "Кількість елементів у рядку на даний момент: " << MyClass6.GetCurrentSize() << endl << endl;
}

/*
Функція Compare для порівняння ємностей двох множин і виводу результату до консолі
Вхід:
MyClass1-перший об'єкт класу, ємність множини якого потрібно порівняти, передача за значенням
MyClass2-другий об'єкт класу, ємність множини якого потрібно порівняти, передача за значенням
Вихід:
-1-якщо одна з множин для порівняння не існує
0-при успішному виконанні функції, якщо перша множина не менша за другу
1-при успішному виконанні функції, якщо перша множина менша за другу
*/
int Compare(MyClass MyClass1, MyClass MyClass2)
{
	cout << "Перша множина для порівняння: ";
	MyClass1.Print();
	cout << endl;
	cout << "Друга множина для порівняння: ";
	MyClass2.Print();
	cout << endl;
	if (MyClass1 < MyClass2 == -2)
	{
		cout << "Одна з множин для порівняння не існує!" << endl;
		return -1;
	}
	else if (MyClass1 < MyClass2 == 1)
	{
		cout << "Множина ";
		MyClass1.Print();
		cout << " менша за множину ";
		MyClass2.Print();
		cout << endl;
		return 1;
	}
	else
	{
		cout << "Множина ";
		MyClass1.Print();
		cout << " не менша за множину ";
		MyClass2.Print();
		cout << endl;
		return 0;
	}
}
