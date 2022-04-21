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
<<<<<<< HEAD
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
=======
����������� ��� ���������
*/
Student::Student()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� �����
	printf("���������� ����������� ��� ��������� - %p\n\n", this);
#endif 
	_name = new char[strlen("�������") + 1];
	if (!_name)
		exit(0);
	strcpy(_name, "�������");
>>>>>>> 86b2a56 (test)
	_course = 0;
	_gender = '-';
}

/*
<<<<<<< HEAD
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
=======
����������� � �����������
����:
name-�������� �� ����������� �����, �������� �� ����������
course-�����, ��� ������ �������� �����, �������� �� ���������
gender-�����, ��� ������ �������� ���� ��������, �������� �� ���������
*/
Student::Student(const char* name, int course, char gender)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� ����� #endif �� ���� �����
	printf("���������� ����������� � ����������� - %p\n\n", this);
>>>>>>> 86b2a56 (test)
#endif 
	_name = new char[strlen(name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, name);
	if (course < 1 || course > 6)
		exit(0);
	else
		_course = course;
<<<<<<< HEAD
	if (gender != 'М' && gender != 'Ж')
=======
	if (gender != '�' && gender != '�')
>>>>>>> 86b2a56 (test)
		exit(0);
	else
		_gender = gender;
}

/*
<<<<<<< HEAD
Конструктор копіювання
Вхід:
other-змінна структурного типу, передача за посиланням
*/
Student::Student(const Student& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі
	printf("Викликався конструктор копіювання - %p\n\n", this);
=======
����������� ���������
����:
other-����� ������������ ����, �������� �� ����������
*/
Student::Student(const Student& other)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif � ���
	printf("���������� ����������� ��������� - %p\n\n", this);
>>>>>>> 86b2a56 (test)
#endif
	_name = new char[strlen(other._name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, other._name);
	_course = other._course;
	_gender = other._gender;
}

/*
<<<<<<< HEAD
Метод SetName структури Student для запису ім'я студента у поле _name
Вхід:
name-вказівник на константний рядок, передача за посиланням
=======
����� SetName ��������� Student ��� ������ ��'� �������� � ���� _name
����:
name-�������� �� ����������� �����, �������� �� ����������
>>>>>>> 86b2a56 (test)
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
<<<<<<< HEAD
Метод SetCourse структури Student для запису курсу студента у поле _course
Вхід:
_course - змінна, яка зберігає значення курсу, передача за значенням
=======
����� SetCourse ��������� Student ��� ������ ����� �������� � ���� _course
����:
_course - �����, ��� ������ �������� �����, �������� �� ���������
>>>>>>> 86b2a56 (test)
*/
void Student::SetCourse(int course)
{
	if (course < 1 || course > 6)
	{
<<<<<<< HEAD
		printf("Курс студента %s не є припустимим!", _name);
=======
		printf("���� �������� %s �� � �����������!", _name);
>>>>>>> 86b2a56 (test)
		exit(0);
	}
	_course = course;
}

/*
<<<<<<< HEAD
Метод SetGender структури Student для запису статі студента у поле _gender
Вхід:
student_gender - змінна, яка зберігає значення статі, передача за значенням
*/
void Student::SetGender(char student_gender)
{
	if (student_gender != 'М' && student_gender != 'Ж')
=======
����� SetGender ��������� Student ��� ������ ���� �������� � ���� _gender
����:
student_gender - �����, ��� ������ �������� ����, �������� �� ���������
*/
void Student::SetGender(char student_gender)
{
	if (student_gender != '�' && student_gender != '�')
>>>>>>> 86b2a56 (test)
		exit(0);
	_gender = student_gender;
}

/*
<<<<<<< HEAD
Метод GetName структури Student без параметрів для отримання значення поля _name об'єкту структури
Результат:
Вказівник на рядок з записаним іменем працівника
=======
����� GetName ��������� Student ��� ��������� ��� ��������� �������� ���� _name ��'���� ���������
���������:
�������� �� ����� � ��������� ������ ����������
>>>>>>> 86b2a56 (test)
*/
char* Student::GetName()
{
	char* newname = new char[strlen(_name) + 1];
	strcpy(newname, _name);
	return newname;
}

/*
<<<<<<< HEAD
Метод GetName структури Student без параметрів для отримання значення поля _name об'єкту структури
Результат:
Вказівник на рядок з записаним іменем працівника
=======
����� GetName ��������� Student ��� ��������� ��� ��������� �������� ���� _name ��'���� ���������
���������:
�������� �� ����� � ��������� ������ ����������
>>>>>>> 86b2a56 (test)
*/
char* Student::GetName(char name[], int num)
{

	strcpy_s(name, num, _name);
	return name;
}

/*
<<<<<<< HEAD
Метод GetCourse структури Student без параметрів для отримання значення поля _course об'єкту структури
Результат:
Курс студената, що записаний у поле _course об'єкту структури
=======
����� GetCourse ��������� Student ��� ��������� ��� ��������� �������� ���� _course ��'���� ���������
���������:
���� ���������, �� ��������� � ���� _course ��'���� ���������
>>>>>>> 86b2a56 (test)
*/
int Student::GetCourse()
{
	return _course;
}

/*
<<<<<<< HEAD
Метод GetGender структури Student без параметрів для отримання значення поля _gender об'єкту структури
Результат:
Стать студента, що записаний у поле _gender об'єкту структури
=======
����� GetGender ��������� Student ��� ��������� ��� ��������� �������� ���� _gender ��'���� ���������
���������:
����� ��������, �� ��������� � ���� _gender ��'���� ���������
>>>>>>> 86b2a56 (test)
*/
char Student::GetGender()
{
	return _gender;
}

/*
<<<<<<< HEAD
Метод Show структури Student без параметрів для виводу в консоль полів об'єкту структури
*/
void Student::Print()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі
	printf("Ім'я: %s\n", _name);
	printf("Курс: %d\n", _course);
	printf("Стать: %s\n\n", &_gender);
=======
����� Show ��������� Student ��� ��������� ��� ������ � ������� ���� ��'���� ���������
*/
void Student::Print()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif � ���
	printf("��'�: %s\n", _name);
	printf("����: %d\n", _course);
	printf("�����: %s\n\n", &_gender);
>>>>>>> 86b2a56 (test)
#endif
}

/*
<<<<<<< HEAD
Деструктор
*/
Student::~Student()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif
	printf("Викликався деструткор - %p\n\n", this);
#endif //якщо ми не ідентифікували DEBUG, то виконується все після #endif
=======
����������
*/
Student::~Student()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif
	printf("���������� ���������� - %p\n\n", this);
#endif //���� �� �� �������������� DEBUG, �� ���������� ��� ���� #endif
>>>>>>> 86b2a56 (test)
	delete[] _name;
}

/*
<<<<<<< HEAD
Метод Set структури Student з параметрами для задання значень полів об'єкту
Вхід:
name-вказівник на константний рядок, передача за посиланням
course-змінна, яка зберігає значення курсу, передача за значенням
student_gender -змінна, яка зберігає значення статі студента, передача за значенням
=======
����� Set ��������� Student � ����������� ��� ������� ������� ���� ��'����
����:
name-�������� �� ����������� �����, �������� �� ����������
course-�����, ��� ������ �������� �����, �������� �� ���������
student_gender -�����, ��� ������ �������� ���� ��������, �������� �� ���������
>>>>>>> 86b2a56 (test)
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
