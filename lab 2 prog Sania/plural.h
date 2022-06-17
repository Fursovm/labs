#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG

const int MAXSIZE = 20;

class Plural
{

public:

	Plural();												// ����������� ��� ���������� ��� ����� Plural
	Plural(char* array, int size);							// ����������� � ����������� ��� ����� Plural
	Plural(const char* arr);								// ����������� � �����������(������ �������) ��� ����� Plural
	Plural(const Plural& exemplar);							// ����������� ���������
	~Plural();												// ����������

	Plural operator+ (const Plural& other);					// �������������� ��������� + (��'������� ������)
	friend Plural operator+(char element, Plural& other);   // �������������� ��������� + (��������� �������� �� �������)
	int operator==(const Plural& other);					// �������������� ��������� ==
	Plural operator= (const Plural& exemplar);				// �������������� ��������� =
	int operator> (char symbol);


	int sizeIncrease(int demandSize);						// �������, �� ������ ������������ �������� ����� ������ ���, ��� _maxSize > demandSize 
	int GetCurrentSize();									// ����� �������� ������ �������
	int GetMaxSize();										// ����� �������� ������������� ������ �������
	char* ToArray();
	int SetPlural(char* arrayOfChar, int size);				// �����, �� ���������� ������� � ������ �������
	int SetPlural(const char* inputArray);					// �����, �� ���������� ������� � ����� (������ ������� � \0 � ����)
	void Print();											// ����� ������ ������� �� �����

private:

	int checkMemory(char* arr);					// ������� �������� �������� ���'�� 

	char* _arr;
	int _maxSize;
	int _currentSize;

	bool Compare(int firstSize, int secondSize); // ������� ��������� ���� �������� �������� ������

};





