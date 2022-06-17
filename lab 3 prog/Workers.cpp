#define _CRT_SECURE_NO_WARNINGS
#include "string.h" 
#include <iostream>
#include "Workers.h"
//#define DEBUG 
using namespace std;

/*
����������� ��� ���������
����: �������
�����: �������
*/
Worker::Worker()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
    cout << "���������� ����������� ��� ��������� ����� Employee - " << this << endl << endl;
#endif 
    _name = "�������";
    _workExperience = 0;
    _age = 0;
    _payment = 0;
    _workingPlace = 0;
}

/*
����������� � �����������
����:
  name - ��'� ��������
  age - �� ��������
  work_experience - ���� ��������
  payment - ��������� ��������
  workingPlace - ���� ������ ��������
�����: �������
*/
Worker::Worker(string name, string profession, int age, int workExperience, double payment, bool workingPlace)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� ����� #endif �� ���� �����
    cout << "���������� ����������� � ����������� ����� Employee - " << this << endl << endl;
#endif
    Set(name, profession, age, workExperience, payment, workingPlace);
}

/*
����������� ���������
����:
  other - ���������� ��������� �� ��'��� ����� Employee
�����: �������
*/
Worker::Worker(const Worker& other)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif � ��� 
    cout << "���������� ����������� ��������� ����� Employee - " << this << endl << endl;
#endif 
    Set(other._name, other._profession, other._age, other._workExperience, other._payment, other._workingPlace);
}

/*
������ ��� ���� ��������
����: �������
�����:
  GetName = newName - ��'� ��������
*/
string Worker::GetName()
{
    return _name;
}

/*
������ ��� ������
����: �������
�����:
    GetProfession = newProfession - ������� ��������
*/
string Worker::GetProfession()
{
    return _profession;
}

/*
������ ��� ��� ��������
����: �������
�����:
  GetAge = _age - �� ��������
*/
int Worker::GetAge()
{
    return _age;
}

/*
������ ��� ����� ��������
����: �������
�����:
  GetExperience = _workExperience - ���� ��������
*/
int Worker::GetExperience()
{
    return _workExperience;
}

/*
������ ��� �������� ��������
����: �������
�����:
  GetPayment = _payment - ��������� ��������
*/
double Worker::GetPayment()
{
    return _payment;
}

/*
������ ��� ���� ������ ��������
����: �������
�����:
  GetWorkingPlace = _workingPlace - ���� ������ ��������
*/
bool Worker::GetWorkingPlace()
{
    return _workingPlace;
}

/*
������ ��� ��� ���� ��'���� �����
����:
  name - ��'� ��������
  age - �� ��������
  work_experience - ���� ��������
  payment - ��������� ��������
  workingPlace - ���� ������ ��������
�����: �������
*/
void Worker::Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace)
{
    SetName(name);
    SetProfession(profession);
    SetAge(age);
    SetExperience(workExperience);
    SetPayment(payment);
    SetWorkingPlace(workingPlace);
}

/*
������ ��� ���� ��������
����:
  name - ��'� ��������
�����: �������
*/
void Worker::SetName(string name)
{
    _name = name;
}

/*
������ ��� ������
����:
    profession - ������� ��� �������
�����: �������
*/
void Worker::SetProfession(string profession)
{
    _profession = profession;
}

/*
������ ��� ��� ��������
����:
  age - �� ��������
�����: �������
*/
void Worker::SetAge(int age)
{
    if (age < 18 || age > 65)
        throw(exception("�� �������� ���������� �������� ��� ��������!"));
    else
        _age = age;
}

/*
������ ��� ����� ��������
����:
  work_experience - ���� ��������
�����: �������
*/
void Worker::SetExperience(int work_experience)
{
    if (work_experience < 0 || work_experience > 46)
        throw(exception("�� �������� ���������� �������� ����� ��������!"));
    else
        _workExperience = work_experience;
}

/*
������ ��� �������� ��������
����:
  payment - ��������� ��������
�����: �������
*/
void Worker::SetPayment(double payment)
{
    if (payment >= 0)
    {
        _payment = payment;
    }
    else
    {
        throw(exception("�� ������ ���������� �������� ��������!"));
    }
}

/*
������ ��� ���� ������ ��������
����:
  workingPlace - ���� ������ ��������
�����: �������
*/
void Worker::SetWorkingPlace(bool workingPlace)
{
    _workingPlace = workingPlace;
}

/*
���������� �����
����: �������
�����: �������
*/
Worker::~Worker()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� �� ���� #endif 
    cout << "���������� ���������� ����� Employee - " << this << endl << endl;
#endif 
}