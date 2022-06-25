#include "Workers.h"

class MarketingSpecialist : public Worker //������������� �� ����� Worker
{
public: //���������� �����, �� ���� ������� �������� ������
	MarketingSpecialist(); //����������� ��� ��������� �� �������������
	MarketingSpecialist(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int tasksNum); //����������� � �����������
	void Show() override; //������� ��� ������ ���������� �� ������
	void Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int tasksNum); //������ ��� ��� ����
	void SetTasksNum(int tasksNum); //������ ��� ������� ����� �� �����
	int GetNum() override; //������ ��� ������� ����� �� �����
	~MarketingSpecialist() override; //���������� �� �������������
protected:
	int _tasksNum; //������� ����� �� �����
};

class BusinessAnalyst : public Worker //������������� �� ����� Worker
{
public: //���������� �����, �� ���� ������� �������� ������
	BusinessAnalyst(); //����������� ��� ��������� �� �������������
	BusinessAnalyst(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int solvingProblems); //����������� � �����������
	void Show() override; //���� ����� ��� �����-�������� �� ������
	void Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int solvingProblems); //������ ��� ��� ����
	void SetSolvingProblems(int solvingProblems); //������ ��� ������� �������� ������� �� �����
	int GetNum() override; //������ ��� ������� �������� ������� �� �����
	~BusinessAnalyst() override; //����������
protected:
	int _solvingProblems; //������� �������� ������� �� �����
};

class AdministrativeAssistant : public Worker //������������� �� ����� Worker
{
public: //���������� �����, �� ���� ������� �������� ������
	AdministrativeAssistant(); //����������� ��� ��������� �� �������������
	AdministrativeAssistant(string name, string profession, int age, int workExperience, double payment, bool workingPlace, bool administratorApproval); //����������� � �����������
	void Show() override; //���� ����� ��� �������� ������������ �� ������
	void Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, bool administratorApproval); //������ ��� ��� ����
	void SetAdministratorApproval(bool administratorApproval); //������ ��� ��������� ������������
	int GetNum() override; //������ ��� ��������� ������������
	~AdministrativeAssistant() override; //����������
protected:
	bool _administratorApproval; //��������� ������������
};