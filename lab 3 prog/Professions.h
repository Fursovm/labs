#include "Workers.h"

class MarketingSpecialist : public Worker //������������� �� ����� Employee
{
public: //���������� �����, �� ���� ������� �������� ������
	MarketingSpecialist() = default; //����������� ��� ��������� �� �������������
	void Show() override; //������� ��� ������ ���������� �� ������
	~MarketingSpecialist() override; //���������� �� �������������
};

class BusinessAnalyst : public Worker //������������� �� ����� Employee
{
public: //���������� �����, �� ���� ������� �������� ������
	BusinessAnalyst() = default; //����������� ��� ��������� �� �������������
	void Show() override; //���� ����� ��� �����-�������� �� ������
	~BusinessAnalyst() override; //����������
};

class AdministrativeAssistant : public Worker //������������� �� ����� Employee
{
public: //���������� �����, �� ���� ������� �������� ������
	AdministrativeAssistant() = default; //����������� ��� ��������� �� �������������
	void Show() override; //���� ����� ��� �������� ������������ �� ������
	~AdministrativeAssistant() override; //����������
};