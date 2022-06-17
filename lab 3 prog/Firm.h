#pragma once
#include "Date.h"
#include "Department.h"
using namespace std;

class Firm
{
public: //���������� �����, �� ���� ������� �������� ������
	Firm(); //����������� ��� ���������
	Firm(vector<Department> items, Date& createdAt, string name, string chiefExecutiveOfficer, double proceeds); //����������� � �����������
	Firm(const Firm& other); //����������� ���������
	Firm(Firm&&) noexcept = delete; //�������� ������������ ����������
	Firm& operator=(Firm&&) = delete; //�������� ���������� �� ��������� ��������� ������������
	Firm& operator=(const Firm&) = default; //��������� �� ��������� ��������� ������������ �� �������������
	Department* GetDepartment(size_t numOfDep); //������ ������ ����������� �����
	int GetNumberOfDepartments(); //������ ��� ��������� ������� ����� ����������
	vector<Department> GetItems(); //������ ��� �����
	string GetCreationDate(); //������ ��� ���� ���������
	string GetName(); //������ ��� ����
	string GetCEO(); //������ ��� ���
	double GetProceeds(); //������ ��� ��������
	void Set(vector<Department> items, Date& createdAt, string name, string chiefExecutiveOfficer, double proceeds); //������ ��� ��� ����
	void SetItems(vector<Department> items); //������ ��� �����
	void SetCreationDate(Date& createdAt); //������ ��� ���� ���������
	void SetName(string name); //������ ��� �����
	void SetCEO(string chiefExecutiveOfficer); //������ ��� ���
	void SetProceeds(double proceeds); //������ ��� ��������
	void Insert(const Department* newDepartment); //���������� ������ �����
	void Show(); //���� ����� ��� ���������� �� ������
	~Firm(); //����������
protected: //���������� �����, �� ���� ��������� ������
	vector<Department> _items; //�����
	Date _createdAt; //���� ���������
	string _name; //�����
	string _chiefExecutiveOfficer; //���
	double _proceeds; //��������
};
