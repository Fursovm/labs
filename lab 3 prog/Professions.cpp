#define _CRT_SECURE_NO_WARNINGS 
#include "Professions.h"
using namespace std;

MarketingSpecialist::MarketingSpecialist()
{
	_profession = "��������� �� ����������";
	_name = "�������";
	_workExperience = 0;
	_age = 0;
	_payment = 0;
	_workingPlace = 0;
	_tasksNum = 0;
}

MarketingSpecialist::MarketingSpecialist(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int tasksNum)
{
	Set(name, profession, age, workExperience, payment, workingPlace, tasksNum);
}

BusinessAnalyst::BusinessAnalyst()
{
	_profession = "������ �������";
	_name = "�������";
	_workExperience = 0;
	_age = 0;
	_payment = 0;
	_workingPlace = 0;
	_solvingProblems = 0;
}

BusinessAnalyst::BusinessAnalyst(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int solvingProblems)
{
	Set(name, profession, age, workExperience, payment, workingPlace, solvingProblems);
}

AdministrativeAssistant::AdministrativeAssistant()
{
	_profession = "������ �����������";
	_name = "�������";
	_workExperience = 0;
	_age = 0;
	_payment = 0;
	_workingPlace = 0;
	_administratorApproval = false;
}

AdministrativeAssistant::AdministrativeAssistant(string name, string profession, int age, int workExperience, double payment, bool workingPlace, bool administratorApproval)
{
	Set(name, profession, age, workExperience, payment, workingPlace, administratorApproval);
}

/*
������� ������ �� ������ ���������� ��� ���������� � ����������
����: �������
�����: �������
*/
void MarketingSpecialist::Show()
{
	cout << "\n��'�: " << _name << endl;
	cout << "³�: " << _age << endl;
	cout << "������� ����: " << _workExperience << endl;
	cout << "������: ��������� � ����������" << endl;
	cout << "ʳ������ ����� �� ����� " << _tasksNum << endl;
	cout << "���������: " << _payment << " ���/�����" << endl;
	if (_workingPlace == true)
	{
		cout << "̳��� ������: � ����" << endl;
	}
	else
	{
		cout << "̳��� ������: �����" << endl;
	}
}

/*
������� ������ �� ������ ���������� ��� �����-��������
����: �������
�����: �������
*/
void BusinessAnalyst::Show()
{
	cout << "\n��'�: " << _name << endl;
	cout << "³�: " << _age << endl;
	cout << "������� ����: " << _workExperience << endl;
	cout << "������: �����-�������" << endl;
	cout << "�������� ������� �� ����� " << _solvingProblems << endl;
	cout << "���������: " << _payment << " ���/�����" << endl;
	if (_workingPlace == true)
	{
		cout << "̳��� ������: � ����" << endl;
	}
	else
	{
		cout << "̳��� ������: �����" << endl;
	}
}

/*
������� ������ �� ������ ���������� ��� �������� ������������
����: �������
�����: �������
*/
void AdministrativeAssistant::Show()
{
	cout << "\n��'�: " << _name << endl;
	cout << "³�: " << _age << endl;
	cout << "������� ����: " << _workExperience << endl;
	cout << "������: ������� ������������" << endl;
	cout << "���������: " << _payment << " ���/�����" << endl;
	if (_administratorApproval)
		cout << "��������� ������������ �" << endl;
	else
		cout << "��������� ������������ ����" << endl;

	if (_workingPlace == true)
	{
		cout << "̳��� ������: � ����" << endl;
	}
	else
	{
		cout << "̳��� ������: �����" << endl;
	}
}

void MarketingSpecialist::Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int tasksNum)
{
	SetName(name);
	SetProfession(profession);
	SetAge(age);
	SetExperience(workExperience);
	SetPayment(payment);
	SetWorkingPlace(workingPlace);
	SetTasksNum(tasksNum);
}

void BusinessAnalyst::Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int solvingProblems)
{
	SetName(name);
	SetProfession(profession);
	SetAge(age);
	SetExperience(workExperience);
	SetPayment(payment);
	SetWorkingPlace(workingPlace);
	SetSolvingProblems(solvingProblems);
}

void AdministrativeAssistant::Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, bool administratorApproval)
{
	SetName(name);
	SetProfession(profession);
	SetAge(age);
	SetExperience(workExperience);
	SetPayment(payment);
	SetWorkingPlace(workingPlace);
	SetAdministratorApproval(administratorApproval);
}

void MarketingSpecialist::SetTasksNum(int tasksNum)
{
	if (tasksNum < 0)
		throw(exception("�� �������� ���������� �������� ����� ��������!"));
	else _tasksNum = tasksNum;
}

void BusinessAnalyst::SetSolvingProblems(int solvingProblems)
{
	if (solvingProblems < 0)
		throw(exception("�� �������� ���������� �������� �������� ������� ��������!"));
	else _solvingProblems = solvingProblems;
}

void AdministrativeAssistant::SetAdministratorApproval(bool administratorApproval)
{
	if (administratorApproval > 1 || administratorApproval < 0)
		throw(exception("�� �������� ���������� �������� ��������� ������������!"));
	else _administratorApproval = administratorApproval;
}

int MarketingSpecialist::GetNum()
{
	return _tasksNum;
}

int BusinessAnalyst::GetNum()
{
	return _solvingProblems;
}

int AdministrativeAssistant::GetNum()
{
	return _administratorApproval;
}


/*
���������� �����
����: �������
�����: �������
*/
BusinessAnalyst::~BusinessAnalyst()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� �� ���� #endif 
	cout << "���������� ���������� ����� BusinessAnalyst - " << this << endl << endl;
#endif 
}

/*
���������� �����
����: �������
�����: �������
*/
MarketingSpecialist::~MarketingSpecialist()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� �� ���� #endif 
	cout << "���������� ���������� ����� MarketingSpecialist - " << this << endl << endl;
#endif 
}

/*
���������� �����
����: �������
�����: �������
*/
AdministrativeAssistant::~AdministrativeAssistant()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� �� ���� #endif 
	cout << "���������� ���������� ����� AdministrativeAssistant - " << this << endl << endl;
#endif 
}
