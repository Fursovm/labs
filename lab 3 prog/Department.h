#pragma once
#include "Professions.h"

class Department
{
public: //���������� �����, �� ���� ������� �������� ������
	Department(); //����������� ��� ���������
	Department(vector<Worker*> workers, string name); //����������� � �����������
	Department(const Department& other); //����������� ���������
	string GetName(); //������ ��� ����� ����� ��� ��������� ������� �������� ��� ������
	vector<Worker*> GetWorkers(); //������ ��� ��� �������� �����
	vector<AdministrativeAssistant> GetWorkersAA();  //������ ��� �������� ������������
	vector<BusinessAnalyst> GetWorkersBA(); //������ ��� �����-��������
	vector<MarketingSpecialist> GetWorkersMS(); //������ ��� ���������� � ����������
	void Set(vector<Worker*> workers, string name); //������ ��� ��� ����
	void SetWorkers(vector<Worker*> workers); //������ ��� ��� �������� �����
	template <typename T>
	void SetWorkersByProf(vector<T>& workers);
	void SetName(string name); //������ ��� �����
	void Insert(Worker* newWorker, string profession); //������ ������ �������� � ����
	void Show(); //���� ����� ��� ���� �� ������
	~Department(); //����������
protected: //���������� �����, �� ���� ��������� ������
	vector<Worker*> _workers; //�������� �����
	string _name; //�����

	template <typename T>
	vector<T> GetWorkersByProf(vector<T>& vector, string profession); //������ ��� �������� �� ������ �������
};