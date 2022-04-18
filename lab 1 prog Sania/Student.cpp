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
	_course = 0;
	_gender = '-';
}

/*
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
#endif 
	_name = new char[strlen(name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, name);
	if (course < 1 || course > 6)
		exit(0);
	else
		_course = course;
	if (gender != '�' && gender != '�')
		exit(0);
	else
		_gender = gender;
}

/*
����������� ���������
����:
other-����� ������������ ����, �������� �� ����������
*/
Student::Student(const Student& other)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif � ���
	printf("���������� ����������� ��������� - %p\n\n", this);
#endif
	_name = new char[strlen(other._name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, other._name);
	_course = other._course;
	_gender = other._gender;
}

/*
����� SetName ��������� Student ��� ������ ��'� �������� � ���� _name
����:
name-�������� �� ����������� �����, �������� �� ����������
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
����� SetCourse ��������� Student ��� ������ ����� �������� � ���� _course
����:
_course - �����, ��� ������ �������� �����, �������� �� ���������
*/
void Student::SetCourse(int course)
{
	if (course < 1 || course > 6)
	{
		printf("���� �������� %s �� � �����������!", _name);
		exit(0);
	}
	_course = course;
}

/*
����� SetGender ��������� Student ��� ������ ���� �������� � ���� _gender
����:
student_gender - �����, ��� ������ �������� ����, �������� �� ���������
*/
void Student::SetGender(char student_gender)
{
	if (student_gender != '�' && student_gender != '�')
		exit(0);
	_gender = student_gender;
}

/*
����� GetName ��������� Student ��� ��������� ��� ��������� �������� ���� _name ��'���� ���������
���������:
�������� �� ����� � ��������� ������ ����������
*/
char* Student::GetName()
{
	char* newname = new char[strlen(_name) + 1];
	strcpy(newname, _name);
	return newname;
}

/*
����� GetName ��������� Student ��� ��������� ��� ��������� �������� ���� _name ��'���� ���������
���������:
�������� �� ����� � ��������� ������ ����������
*/
char* Student::GetName(char name[], int num)
{

	strcpy_s(name, num, _name);
	return name;
}

/*
����� GetCourse ��������� Student ��� ��������� ��� ��������� �������� ���� _course ��'���� ���������
���������:
���� ���������, �� ��������� � ���� _course ��'���� ���������
*/
int Student::GetCourse()
{
	return _course;
}

/*
����� GetGender ��������� Student ��� ��������� ��� ��������� �������� ���� _gender ��'���� ���������
���������:
����� ��������, �� ��������� � ���� _gender ��'���� ���������
*/
char Student::GetGender()
{
	return _gender;
}

/*
����� Show ��������� Student ��� ��������� ��� ������ � ������� ���� ��'���� ���������
*/
void Student::Print()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif � ���
	printf("��'�: %s\n", _name);
	printf("����: %d\n", _course);
	printf("�����: %s\n\n", &_gender);
#endif
}

/*
����������
*/
Student::~Student()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif
	printf("���������� ���������� - %p\n\n", this);
#endif //���� �� �� �������������� DEBUG, �� ���������� ��� ���� #endif
	delete[] _name;
}

/*
����� Set ��������� Student � ����������� ��� ������� ������� ���� ��'����
����:
name-�������� �� ����������� �����, �������� �� ����������
course-�����, ��� ������ �������� �����, �������� �� ���������
student_gender -�����, ��� ������ �������� ���� ��������, �������� �� ���������
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