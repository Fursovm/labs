#define _CRT_SECURE_NO_WARNINGS 
#include "string.h" 
#include <iostream>
#include <vector>
#include "Firm.h"
//#define DEBUG
using namespace std;

/*
����������� ��� ���������
����: �������
�����: �������
*/
Firm::Firm()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
	cout << "���������� ����������� ��� ��������� ����� Enterprice - " << this << endl << endl;
#endif 
	_proceeds = 0;
}

/*
����������� � �����������
����:
	items - ����� ����������
	createdAt - ���� ����������
	name - ����� ����������
	chiefExecutiveOfficer - CEO ����������
	proceeds - �������� ����������
�����: �������
*/
Firm::Firm(vector<Department> items, Date& createdAt, string name, string chiefExecutiveOfficer, double proceeds)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
	cout << "���������� ����������� � ����������� ����� Enterprice - " << this << endl << endl;
#endif 
	Set(items, createdAt, name, chiefExecutiveOfficer, proceeds);
}

/*
����������� ���������
����:
	other - ���������� ��������� �� ��'��� ����� Enterprise
�����: �������
*/
Firm::Firm(const Firm& other)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
	cout << "���������� ����������� ��������� ����� Enterprice - " << this << endl << endl;
#endif
	Set(other._items, *const_cast<Date*>(&other._createdAt), other._name, other._chiefExecutiveOfficer, other._proceeds);
}

/*
����� ��� ��������� ������ ����������� �����
����:
	numOfDep - ����� �����, ������ �� ���� ���������� ���� ��������
�����:
	GetDepartment = &_items[numOfDep - 1] - ��������� �� ���������� ����
*/
Department* Firm::GetDepartment(size_t numOfDep)
{
	if (numOfDep > _items.size())
	{
		throw(exception("�� �������� ������ ����� �����, �� �� � � ����������!"));
	}
	else
	{
		return &_items[numOfDep - 1];
	}
}

/*
������ ��� ��������� ������� ����� ����������
����: �������
�����:
	GetNumberOfDepartments = _items.size() - ������� �����
*/
int Firm::GetNumberOfDepartments()
{
	return _items.size();
}

/*
������ ��� ����� ����������
����: �������
�����:
	GetItems = items - ����� ����������
*/
vector<Department> Firm::GetItems()
{
	vector<Department> items;
	for (auto item = _items.begin(); item != _items.end(); item++)
	{
		items.emplace_back(*item);
	}
	return items;
}

/*
������ ��� ���� ���������� ����������
����: �������
�����:
	GetCreationDate = creationDate - ���� ���������� ����������
*/
string Firm::GetCreationDate()
{
	string day = "";
	if (_createdAt.GetDay() < 10)
	{
		day = "0";
		day += _createdAt.GetDay();
	}
	else
	{
		day = _createdAt.GetDay();
	}
	string creationDate;
	creationDate = _createdAt.GetYear();
	creationDate += ".";
	creationDate += _createdAt.GetMonth();
	creationDate += ".";
	creationDate += day;
	return creationDate;
}

/*
������ ��� ����� ����������
����: �������
�����:
	GetName = _name - ����� ����������
*/
string Firm::GetName()
{
	return _name;
}

/*
������ ��� ��� ����������
����: �������
�����:
	GetCEO = _chiefExecutiveOfficer - ��� ����������
*/
string Firm::GetCEO()
{
	return _chiefExecutiveOfficer;
}

/*
������ ��� �������� ����������
����: �������
�����:
	GetProceeds = _proceeds - �������� ����������
*/
double Firm::GetProceeds()
{
	return _proceeds;
}

/*
������ ��� ��� ���� ��'���� �����
����:
	items - ����� ����������
	createdAt - ���� ���������� ����������
	name - ����� ����������
	chiefExecutiveOfficer - ��� ����������
	proceeds - �������� ����������
�����: �������
*/
void Firm::Set(vector<Department> items, Date& createdAt, string name, string chiefExecutiveOfficer, double proceeds)
{
	SetItems(items);
	SetCreationDate(createdAt);
	SetName(name);
	SetCEO(chiefExecutiveOfficer);
	SetProceeds(proceeds);
}

/*
������ ��� ����� ����������
����:
	items - ��������� �� ����� ����������
�����: �������
*/
void Firm::SetItems(vector<Department> items)
{
	static_cast<void>(items.at(0));
	_items.clear();
	for (auto item = items.begin(); item != items.end(); item++)
	{
		_items.emplace_back(*item);
	}
}

/*
������ ��� ���� ���������� ����������
����:
	createdAt - ���� ���������� ����������
�����: �������
*/
void Firm::SetCreationDate(Date& createdAt)
{
	if (createdAt.GetYear() == "�������" || createdAt.GetMonth() == "�������" || createdAt.GetDay() == 0)
	{
		throw(exception("�� �� �������� ���� ����������!"));
	}
	_createdAt = createdAt;
}

/*
������ ��� ����� ����������
����:
	name - ����� ����������
�����: �������
*/
void Firm::SetName(string name)
{
	_name = name;
}

/*
������ ��� ��� ����������
����:
	chiefExecutiveOfficer - ��� ����������
�����: �������
*/
void Firm::SetCEO(string chiefExecutiveOfficer)
{
	_chiefExecutiveOfficer = chiefExecutiveOfficer;
}

/*
������ ��� �������� ����������
����:
	proceeds - �������� ����������
�����: �������
*/
void Firm::SetProceeds(double proceeds)
{
	_proceeds = proceeds;
}

/*
����� ��� ��������� ������ ����� ����������
����:
	newDepartment - ���������� ������ ������ �����
�����: �������
*/
void Firm::Insert(const Department* newDepartment)
{
	if (newDepartment == NULL)
	{
		throw(exception("�� �� �������� ����� ����!"));
	}
	_items.push_back(*newDepartment);
}

/*
������� ������ �� ������ ���������� ��� ����������
����: �������
�����: �������
*/
void Firm::Show()
{
	if (_createdAt.GetDay() < 10)
	{
		cout << "���� ��������� ����������: 0" << _createdAt.GetDay() << "." << _createdAt.GetMonth() << "." << _createdAt.GetYear() << endl;
	}
	else
	{
		cout << "���� ��������� ����������: " << _createdAt.GetDay() << "." << _createdAt.GetMonth() << "." << _createdAt.GetYear() << endl;
	}
	cout << "����� ����������: " << _name << endl;
	cout << "CEO ����������: " << _chiefExecutiveOfficer << endl;
	cout << "³���� ����������:" << endl;
	int counter = 1;
	for (auto item : _items)
	{
		cout << "\n³��� �" << counter << ":" << endl;
		item.Show();
		counter++;
	}
}

/*
���������� �����
����: �������
�����: �������
*/
Firm::~Firm()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� �� ���� #endif 
	cout << "���������� ���������� ����� Enterprice - " << this << endl << endl;
#endif 
}