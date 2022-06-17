#include <iostream>
using namespace std;

class Date
{
public: //���������� �����, �� ���� ������� �������� ������
	Date(); //����������� ��� ���������
	Date(string year, string month, const int day); //����������� � �����������
	Date(const Date& other); //����������� ���������
	Date(Date&&) noexcept = default; //����������� ���������� �� �������������
	Date& operator=(Date&&) = default; //���������� �� ��������� ��������� ������������ �� �������������
	Date& operator=(const Date&) = default; //��������� �� ��������� ��������� ������������ �� �������������
	string GetYear(); //������ ��� ���� ��� ���������� ������� �������� ��� ������
	string GetMonth(); //������ ��� ����� ��� ��������� ������� �������� ��� ������
	int GetDay(); //������ ��� ���
	void Set(string year, string month, const int day); //������ ��� ��� ����
	void SetYear(string year); //������ ��� ����
	void SetMonth(string month); //������ ��� ����
	void SetDay(const int day); //������ ��� ����
	void Show(); //���� ����� ��� ���� �� ������
	~Date(); //����������
protected: //���������� �����, �� ���� ��������� ������
	string _year, //��
		_month; //�����
	int _day; //����
};