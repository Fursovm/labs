#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Workers.h"
#define DEBUG

/*
����������� ��� ���������
*/
Worker::Worker()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� �����
	printf("���������� ����������� ��� ��������� - %p\n\n", this);
#endif 
	_name = new char[strlen("�������") + 1];
	if (!_name)
		exit(0);
	strcpy(_name, "�������");
	_age = 0;
	_workExperience = 0;
}

/*
����������� � �����������
����:
name-�������� �� ����������� �����, �������� �� ����������
age-�����, ��� ������ �������� ���, �������� �� ���������
work_experience-�����, ��� ������ �������� ������, �������� �� ���������
*/
Worker::Worker(const char* name, int age, int work_experience)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� ����� #endif �� ���� �����
	printf("���������� ����������� � ����������� - %p\n\n", this);
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
����������� ���������
����:
other-����� ������������ ����, �������� �� ����������
*/
Worker::Worker(const Worker& other)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif � ���
	printf("���������� ����������� ��������� - %p\n\n", this);
#endif
	_name = new char[strlen(other._name) + 1];
	if (!_name)
		exit(0);
	strcpy(_name, other._name);
	_age = other._age;
	_workExperience = other._workExperience;
}

/*
����� SetName ��������� Worker ��� ������ ��'� �������� � ���� _name
����:
name-�������� �� ����������� �����, �������� �� ����������
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
����� SetAge ��������� Worker ��� ������ ��� �������� � ���� _age
����:
age-�����, ��� ������ �������� ���, �������� �� ���������
*/
void Worker::SetAge(int age)
{
	if (age < 18 || age > 65)
	{
		printf("³� �������� %s �� � �����������!", _name);
		exit(0);
	}
	_age = age;
}

/*
����� SetExperience ��������� Worker ��� ������ ����� �������� � ���� _workExperience
����:
work_experience-�����, ��� ������ �������� ������, �������� �� ���������
*/
void Worker::SetExperience(int work_experience)
{
	if (work_experience < 0 || work_experience > 46)
	{
		printf("���� �������� %s �� � �����������!", _name);
		exit(0);
	}
	_workExperience = work_experience;
}

/*
����� GetName ��������� Worker ��� ��������� ��� ��������� �������� ���� _name ��'���� ���������
���������:
�������� �� ����� � ��������� ������ ����������
*/
char* Worker::GetName()
{
	char* newname = new char[strlen(_name) + 1];
	strcpy(newname, _name);
	return newname;
}

/*
����� GetName ��������� Worker ��� ��������� ��� ��������� �������� ���� _name ��'���� ���������
���������:
�������� �� ����� � ��������� ������ ����������
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
����� GetAge ��������� Worker ��� ��������� ��� ��������� �������� ���� _age ��'���� ���������
���������:
³� ��������, �� ��������� � ���� _age ��'���� ���������
*/
int Worker::GetAge()
{
	return _age;
}

/*
����� GetExperience ��������� Worker ��� ��������� ��� ��������� �������� ���� _workExperience ��'���� ���������
���������:
���� ��������, �� ��������� � ���� _workExperience ��'���� ���������
*/
int Worker::GetExperience()
{
	return _workExperience;
}

/*
����� Show ��������� Worker ��� ��������� ��� ������ � ������� ���� ��'���� ���������
*/
void Worker::Print()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif � ���
	printf("��'�: %s\n", _name);
	printf("³�: %d\n", _age);
	printf("���� ������: %d\n\n", _workExperience);
#endif
}

/*
����������
*/
Worker::~Worker()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif
	printf("���������� ���������� - %p\n\n", this);
#endif //���� �� �� �������������� DEBUG, �� ���������� ��� ���� #endif
	delete[] _name;
}

/*
����� Set ��������� Worker � ����������� ��� ������� ������� ���� ��'����
����:
name-�������� �� ����������� �����, �������� �� ����������
age-�����, ��� ������ �������� ���, �������� �� ���������
work_experience-�����, ��� ������ �������� ������, �������� �� ���������
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