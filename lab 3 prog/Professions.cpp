#define _CRT_SECURE_NO_WARNINGS 
#include "Professions.h"
using namespace std;

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