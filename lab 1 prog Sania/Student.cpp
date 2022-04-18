#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "locale.h"
#include "string.h"
#include "windows.h"
#include "Student.h"
#define DEBUG

/*
Конструктор без параметрів
*/
Student::Student()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього
	printf("Викликався конструктор без параметрів - %p\n\n", this);
#endif 
	_name = new char[strlen("Невідомо") + 1];
	if (!_name)
		exit(0);
	strcpy(_name, "Невідомо");
	_course = 0;
	_gender = '-';
}

/*
Конструктор з параметрами
Вхід:
name-вказівник на константний рядок, передача за посиланням
course-змінна, яка зберігає значення курсу, передача за значенням
gender-змінна, яка зберігає значення статі студента, передача за значенням
*/
Student::Student(const char* name, int course, char gender)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до рядку #endif та після нього
	printf("Викликався конструктор з параметрами - %p\n\n", this);
#endif 
	_name = new char[strlen(name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, name);
	if (course < 1 || course > 6)
		exit(0);
	else
		_course = course;
	if (gender != 'М' && gender != 'Ж')
		exit(0);
	else
		_gender = gender;
}

/*
Конструктор копіювання
Вхід:
other-змінна структурного типу, передача за посиланням
*/
Student::Student(const Student& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі
	printf("Викликався конструктор копіювання - %p\n\n", this);
#endif
	_name = new char[strlen(other._name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, other._name);
	_course = other._course;
	_gender = other._gender;
}

/*
Метод SetName структури Student для запису ім'я студента у поле _name
Вхід:
name-вказівник на константний рядок, передача за посиланням
*/
void Student::SetName(const char* name)
{
	if (_name)
		delete[] _name;
	_name = new char[strlen(name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, name);
}

/*
Метод SetCourse структури Student для запису курсу студента у поле _course
Вхід:
_course - змінна, яка зберігає значення курсу, передача за значенням
*/
void Student::SetCourse(int course)
{
	if (course < 1 || course > 6)
	{
		printf("Курс студента %s не є припустимим!", _name);
		exit(0);
	}
	_course = course;
}

/*
Метод SetGender структури Student для запису статі студента у поле _gender
Вхід:
student_gender - змінна, яка зберігає значення статі, передача за значенням
*/
void Student::SetGender(char student_gender)
{
	if (student_gender != 'М' && student_gender != 'Ж')
		exit(0);
	_gender = student_gender;
}

/*
Метод GetName структури Student без параметрів для отримання значення поля _name об'єкту структури
Результат:
Вказівник на рядок з записаним іменем працівника
*/
char* Student::GetName()
{
	char* newname = new char[strlen(_name) + 1];
	strcpy(newname, _name);
	return newname;
}

/*
Метод GetName структури Student без параметрів для отримання значення поля _name об'єкту структури
Результат:
Вказівник на рядок з записаним іменем працівника
*/
char* Student::GetName(char name[], int num)
{

	strcpy_s(name, num, _name);
	return name;
}

/*
Метод GetCourse структури Student без параметрів для отримання значення поля _course об'єкту структури
Результат:
Курс студената, що записаний у поле _course об'єкту структури
*/
int Student::GetCourse()
{
	return _course;
}

/*
Метод GetGender структури Student без параметрів для отримання значення поля _gender об'єкту структури
Результат:
Стать студента, що записаний у поле _gender об'єкту структури
*/
char Student::GetGender()
{
	return _gender;
}

/*
Метод Show структури Student без параметрів для виводу в консоль полів об'єкту структури
*/
void Student::Print()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі
	printf("Ім'я: %s\n", _name);
	printf("Курс: %d\n", _course);
	printf("Стать: %s\n\n", &_gender);
#endif
}

/*
Деструктор
*/
Student::~Student()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif
	printf("Викликався деструткор - %p\n\n", this);
#endif //якщо ми не ідентифікували DEBUG, то виконується все після #endif
	delete[] _name;
}

/*
Метод Set структури Student з параметрами для задання значень полів об'єкту
Вхід:
name-вказівник на константний рядок, передача за посиланням
course-змінна, яка зберігає значення курсу, передача за значенням
student_gender -змінна, яка зберігає значення статі студента, передача за значенням
*/
void Student::Set(const char* name, int course, char student_gender)
{
	if (_name)
		delete[] _name;
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
	_course = course;
	_gender = student_gender;
}