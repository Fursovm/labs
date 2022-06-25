#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Worker
{
public: //���������� �����, �� ���� ������� �������� ������  
	Worker(); //����������� ��� ���������
	Worker(string name, string profession, int age, int work_experience, double payment, bool workingPlace); //����������� � �����������
	Worker(const Worker& other); //����������� ���������
	Worker(Worker&&) noexcept = default;
	Worker& operator=(Worker&&) = default;
	Worker& operator=(const Worker&) = default; //��������� �� ��������� ��������� ������������ �� �������������
	string GetName(); //������ ��� ���� ��� ��������� ������� �������� ��� ������
	string GetProfession(); //������ ��� ������
	int GetAge(); //������ ��� ���
	int GetExperience(); //������ ��� ����� ������
	double GetPayment(); //������ ��� ��������
	bool GetWorkingPlace(); //������ ��� ���� ������
	virtual int GetNum();
	void Set(string name, string profession, int age, int work_experience, double payment, bool workingPlace); //������ ��� ��� ����
	void SetName(string name); //������ ��� ����
	void SetProfession(string profession); //������ ��� ������
	void SetAge(int age); //������ ��� ���
	void SetExperience(int work_experience); //������ ��� ����� ������
	void SetPayment(double payment); //������ ��� ��������
	void SetWorkingPlace(bool workingPlace); //������ ��� ���� ������
	virtual void Show();
	Worker ComparePayment(const Worker& worker);
	virtual ~Worker(); //���������� �� �������������
protected: //���������� �����, �� ���� ��������� ������
	string _name; //��'� ��������
	string _profession; //�������
	int _age; //�� ��������
	int _workExperience; //���� ������ ��������
	double _payment; //���������
	bool _workingPlace; //���� ������(����� �� � ����)
};