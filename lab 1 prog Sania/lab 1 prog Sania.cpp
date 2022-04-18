#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include "Student.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Student student1;

	student1.SetName("Олег");
	student1.SetCourse(5);
	student1.SetGender('М');
	student1.Print();

	Student student2("Олена", 3, 'Ж');
	student2.Print();

	Student student3(student2);
	student3.Print();

	Student* student5 = new Student("Михайло", 3, 'М');
	student5->Print();
	delete student5;

	Student student6("Андрій", 4, 'М');
	printf("Ім'я: %s\n", student6.GetName());
	printf("Курс: %d\n", student6.GetCourse());
	printf("Стать: %c\n\n", student6.GetGender());

	Student student7;

	student7.Set("Владлєн", 20, 'М');

	student7.Print();

	_getch();

	return 0;
}