#define _CRT_SECURE_NO_WARNINGS 
#include "string.h" 
#include <iostream>
#include "Date.h" 
//#define DEBUG
using namespace std;

/*
����������� ��� ���������
����: �������
�����: �������
*/
Date::Date()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
	cout << "���������� ����������� ��� ��������� ����� Date - " << this << endl << endl;
#endif 
	Set("�������", "�������", 0);
}

/*
����������� � �����������
����:
	year - �� ����������
	month - ����� ����������
	day - ���� ����������
�����: �������
*/
Date::Date(string year, string month, const int day)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� ����� #endif �� ���� �����
	cout << "���������� ����������� � ����������� ����� Date - " << this << endl << endl;
#endif 
	Set(year, month, day);
}

/*
����������� ���������
����:
	other - ���������� ��������� �� ��'��� ����� Date
�����: �������
*/
Date::Date(const Date& other)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif � ��� 
	cout << "���������� ����������� ��������� ����� Date - " << this << endl << endl;
#endif 
	Set(other._year, other._month, other._day);
}

/*
������ ��� ���� ����������
����: �������
�����:
	GetYear = newYear - �� ����������
*/
string Date::GetYear()
{
	return _year;
}

/*
������ ��� ����� ����������
����: �������
�����:
	GetMonth = newMonth - ����� ����������
*/
string Date::GetMonth()
{
	return _month;
}

/*
������ ��� ��� ����������
����: �������
�����:
	GetDay = _day - ���� ����������
*/
int Date::GetDay()
{
	return _day;
}

/*
������ ��� ��� ���� ��'���� �����
����:
	year - �� ����������
	month - ����� ����������
	day - ���� ����������
�����: �������
*/
void Date::Set(string year, string month, const int day)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);
}

/*
������ ��� ���� ����������
����:
	year - �� ����������
�����: �������
*/
void Date::SetYear(string year)
{
	_year = year;
}

/*
������ ��� ����� ����������
����:
	month - ����� ����������
�����: �������
*/
void Date::SetMonth(string month)
{
	_month = month;
}

/*
������ ��� ��� ����������
����:
	day - ���� ����������
�����: �������
*/
void Date::SetDay(const int day)
{
	if (day < 0 || day > 30)
		throw(exception("�� �������� ���������� �������� ���!"));
	else
		_day = day;
}

/*
����� ������ ����� ��� ���� ���������� �� ������
����: �������
�����: �������
*/
void Date::Show()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif � ��� 
	cout << "г�: " << _year << endl;
	cout << "̳����: " << _month << endl;
	cout << "����: " << _day << endl << endl;
#endif 
}

/*
���������� �����
����: �������
�����: �������
*/
Date::~Date()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� �� ���� #endif 
	cout << "���������� ���������� ����� Date - " << this << endl << endl;
#endif 
}