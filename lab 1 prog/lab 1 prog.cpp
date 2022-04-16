#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include "Workers.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Worker worker1;

	worker1.SetName("Гаврило");
	worker1.SetAge(55);
	worker1.SetExperience(20);
	worker1.Print();

	Worker worker2("Грицько", 18, 0);
	worker2.Print();

	Worker worker3(worker2);
	worker3.Print();

	Worker* worker5 = new Worker("Митько", 30, 5);
	worker5->Print();
	delete worker5;

	Worker worker6("Владлєн", 48, 22);
	printf("Ім'я: %s\n", worker6.GetName());
	printf("Вік: %d\n", worker6.GetAge());
	printf("Стаж роботи: %d\n\n", worker6.GetExperience());

	Worker worker7("Владлєн", 48, 22);
	char name[5];
	worker7.GetName(name, 5);

	printf("Ім'я: %s\n", name);

	_getch();

	return 0;
}