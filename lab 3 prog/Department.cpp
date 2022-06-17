#define _CRT_SECURE_NO_WARNINGS 
#include "string.h" 
#include <iostream>
#include <vector>
#include <algorithm>
#include "Department.h"
//#define DEBUG
using namespace std;

/*
����������� ��� ���������
����: �������
�����: �������
*/
Department::Department()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
    cout << "���������� ����������� ��� ��������� ����� Department - " << this << endl << endl;
#endif 
    _name = "�������";
}

/*
����������� � �����������
����:
  workers - �������� ��� �������
  name - ����� �����
�����: �������
*/
Department::Department(vector<Worker*> workers, string name)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
    cout << "���������� ����������� � ����������� ����� Department - " << this << endl << endl;
#endif 
    Set(workers, name);
}

/*
����������� ���������
����:
  other - ���������� ��������� �� ��'��� ����� Department
�����: �������
*/
Department::Department(const Department& other)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
    cout << "���������� ����������� ��������� ����� Department - " << this << endl << endl;
#endif
    Set(other._workers, other._name);
}

/*
���������� �����
����: �������
�����: �������
*/
Department::~Department()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� �� ���� #endif 
    cout << "���������� ���������� ����� Department - " << this << endl << endl;
#endif 
}

/*
������ ��� ����� �����
����: �������
�����:
  GetName = newName - ����� �����
*/
string Department::GetName()
{
    return _name;
}

/*
������ ��� ��� �������� �����
����: �������
�����:
  GetWorkers = newWorkers - �� �������� �����
*/
vector<Worker*> Department::GetWorkers()
{
    vector<Worker*> newWorkers;
    for (auto worker : _workers)
    {
        newWorkers.emplace_back(worker);
    }
    return newWorkers;
}

/*
������ ��� �������� ������������
����: �������
�����:
  GetWorkersAA = vAA - �������� ������������
*/
vector<AdministrativeAssistant> Department::GetWorkersAA()
{
    vector<AdministrativeAssistant> vAA;
    return GetWorkersByProf(vAA, "������� ������������");
}

/*
������ ��� �����-��������
����: �������
�����:
  GetWorkersBA = vBA - �����-��������
*/
vector<BusinessAnalyst> Department::GetWorkersBA()
{
    vector<BusinessAnalyst> vBA;
    return GetWorkersByProf(vBA, "������-�������");
}

/*
������ ��� ���������� � ����������
����: �������
�����:
  GetWorkersMS = vMS - ���������� � ����������
*/
vector<MarketingSpecialist> Department::GetWorkersMS()
{
    vector<MarketingSpecialist> vMS;
    return GetWorkersByProf(vMS, "��������� � ����������");
}

/*
������ ��� ��� ���� ��'���� �����
����:
  workers - �������� ��� �������
  name - ����� �����
�����: �������
*/
void Department::Set(vector<Worker*> workers, string name)
{
    SetWorkers(workers);
    SetName(name);
}

/*
������ ��� ��� �������� �����
����:
    workers - �������� ��� �������
�����: �������
*/
void Department::SetWorkers(vector<Worker*> workers)
{
    static_cast<void>(workers.at(0));
    _workers.clear();
    for (auto worker : workers)
    {
        _workers.emplace_back(worker);
    }
}

/*
������ ��� �������� ����� ������
����:
    workers - �������� ��� �������
�����: �������
*/
template <typename T>
void Department::SetWorkersByProf(vector<T>& workers)
{
    auto toDelete = remove_if(_workers.begin(), _workers.end(), [workers](Worker* worker)
        {
            return worker->GetProfession() == workers[0]->GetProfession();
        });
    _workers.erase(toDelete, _workers.end());
    for (auto worker : workers)
    {
        _workers.emplace_back(worker);
    }
}

template
void Department::SetWorkersByProf(vector<AdministrativeAssistant*>& workers);
template
void Department::SetWorkersByProf(vector<BusinessAnalyst*>& workers);
template
void Department::SetWorkersByProf(vector<MarketingSpecialist*>& workers);

/*
������ ��� ����� �����
����:
  name - ����� �����
�����: �������
*/
void Department::SetName(string name)
{
    _name = name;
}

/*
����� ��������� ������ �������� � ����
����:
    newWorker - ����� �������, �������� �� ����������
    profession - ������ ������ ��������
�����: �������
*/
void Department::Insert(Worker* newWorker, string profession)
{
    if (newWorker == NULL)
    {
        throw(exception("�� �� �������� ������ ��������!"));
    }
    auto iterator = _workers.begin();
    int iCurrent = 0,
        iPrevious = 0;
    for (auto worker : _workers)
    {
        if (worker->GetProfession() == profession)
        {
            advance(iterator, iCurrent - iPrevious);
            iPrevious = iCurrent;
        }
        iCurrent++;
    }
    _workers.insert(iterator, newWorker);
}

/*
����� ������ ���������� ��� ����
����: �������
�����: �������
*/
void Department::Show()
{
    cout << "�����: " << _name << endl;
    cout << "���������� � ����� ����:";
    int counter = 1;
    for (auto worker : _workers)
    {
        cout << "\n��������� �" << counter << ":";
        worker->Show();
        counter++;
    }
    cout << endl << endl;
}

template <typename T>
/*
������ ��� �������� �� ������ �������
����:
    vector - ��������� ��� �������� �� ������� �������, �������� �� ����������
    profession - ������� ��������
�����:
    GetWorkersByProf = vector - ��������� �� ���������� � ������� �������
*/
vector<T> Department::GetWorkersByProf(vector<T>& vector, string profession)
{
    int j = 0;
    for (auto i = _workers.begin(); i != _workers.end(); i++, j++)
    {
        if (_workers.at(j)->GetProfession() == profession)
        {
            T AA;
            AA.Set(_workers.at(j)->GetName(), _workers.at(j)->GetProfession(), _workers.at(j)->GetAge(), _workers.at(j)->GetExperience(), _workers.at(j)->GetPayment(), _workers.at(j)->GetWorkingPlace());
            vector.emplace_back(AA);
        }
    }
    return vector;
}