#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Workers.h"
#define DEBUG

/*
Конструктор без параметрів
*/
Worker::Worker()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього
	printf("Викликався конструктор без параметрів - %p\n\n", this);
#endif 
	_name = new char[strlen("Невідомо") + 1];
	if (!_name)
		exit(0);
	strcpy(_name, "Невідомо");
	_age = 0;
	_workExperience = 0;
}

/*
Конструктор з параметрами
Вхід:
name-вказівник на константний рядок, передача за посиланням
age-змінна, яка зберігає значення віку, передача за значенням
work_experience-змінна, яка зберігає значення досвіду, передача за значенням
*/
Worker::Worker(const char* name, int age, int work_experience)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до рядку #endif та після нього
	printf("Викликався конструктор з параметрами - %p\n\n", this);
#endif 
	_name = new char[strlen(name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, name);
	if (age < 18 || age > 65)
		exit(0);
	else
		_age = age;
	if (work_experience < 0 || work_experience > 47)
		exit(0);
	else
		_workExperience = work_experience;
}

/*
Конструктор копіювання
Вхід:
other-змінна структурного типу, передача за посиланням
*/
Worker::Worker(const Worker& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі
	printf("Викликався конструктор копіювання - %p\n\n", this);
#endif
	_name = new char[strlen(other._name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, other._name);
	_age = other._age;
	_workExperience = other._workExperience;
}

/*
Метод SetName структури Worker для запису ім'я робітника у поле _name
Вхід:
name-вказівник на константний рядок, передача за посиланням
*/
void Worker::SetName(const char* name)
{
	if (_name)
		delete[] _name;
	_name = new char[strlen(name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, name);
}

/*
Метод SetAge структури Worker для запису віку робітника у поле _age
Вхід:
age-змінна, яка зберігає значення віку, передача за значенням
*/
void Worker::SetAge(int age)
{
	if (age < 18 || age > 65)
	{
		printf("Вік робітника %s не є припустимим!", _name);
		exit(0);
	}
	_age = age;
}

/*
Метод SetExperience структури Worker для запису стажу робітника у поле _workExperience
Вхід:
work_experience-змінна, яка зберігає значення досвіду, передача за значенням
*/
void Worker::SetExperience(int work_experience)
{
	if (work_experience < 0 || work_experience > 46)
	{
		printf("Стаж робітника %s не є припустимим!", _name);
		exit(0);
	}
	_workExperience = work_experience;
}

/*
Метод GetName структури Worker без параметрів для отримання значення поля _name об'єкту структури
Результат:
Вказівник на рядок з записаним іменем працівника
*/
char* Worker::GetName()
{
	char* newname = new char[strlen(_name) + 1];
	strcpy(newname, _name);
	return newname;
}

/*
Метод GetName структури Worker без параметрів для отримання значення поля _name об'єкту структури
Результат:
Вказівник на рядок з записаним іменем працівника
*/
char* Worker::GetName(char name[], int num)
{
	if (num >= strlen(_name) + 1)
		strcpy(name, _name);
	else
	{
		for (int i = 0; i < num - 1; i++)
			name[i] = _name[i];
		name[num - 1] = '\0';
	}
	return name;
}

/*
Метод GetAge структури Worker без параметрів для отримання значення поля _age об'єкту структури
Результат:
Вік робітника, що записаний у поле _age об'єкту структури
*/
int Worker::GetAge()
{
	return _age;
}

/*
Метод GetExperience структури Worker без параметрів для отримання значення поля _workExperience об'єкту структури
Результат:
Стаж робітника, що записаний у поле _workExperience об'єкту структури
*/
int Worker::GetExperience()
{
	return _workExperience;
}

/*
Метод Show структури Worker без параметрів для виводу в консоль полів об'єкту структури
*/
void Worker::Print()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі
	printf("Ім'я: %s\n", _name);
	printf("Вік: %d\n", _age);
	printf("Стаж роботи: %d\n\n", _workExperience);
#endif
}

/*
Деструктор
*/
Worker::~Worker()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif
	printf("Викликався деструткор - %p\n\n", this);
#endif //якщо ми не ідентифікували DEBUG, то виконується все після #endif
	delete[] _name;
}

/*
Метод Set структури Worker з параметрами для задання значень полів об'єкту
Вхід:
name-вказівник на константний рядок, передача за посиланням
age-змінна, яка зберігає значення віку, передача за значенням
work_experience-змінна, яка зберігає значення досвіду, передача за значенням
*/
void Worker::Set(const char* name, int age, int work_experience)
{
	if (_name)
		delete[] _name;
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
	_age = age;
	_workExperience = work_experience;
}