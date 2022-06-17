#pragma once
class Set
{

public:

	Set();												// ����������� ��� ���������� ��� ����� Set
	Set(char* array, int size);							// ����������� � ����������� ��� ����� Set
	Set(const char* array);								// ����������� � �����������(������ �������) ��� ����� Set
	Set(const Set& exemplar);							// ����������� ���������
	~Set();												// ����������

	Set operator+ (const Set& other);					// �������������� ��������� + (��'������� ������)
	friend Set operator+(char element, Set& other);    // �������������� ��������� + (��������� �������� �� �������)
	int operator==(const Set& other);					// �������������� ��������� ==
	Set operator= (const Set& exemplar);				// �������������� ��������� =
	int operator> (char symbol);

	int sizeUp(int demandSize);						// �������, �� ������ ������������ �������� ����� ������ ���, ��� _maxSize > demandSize 
	void ForArr(const char* data, int size);
	int GetCurrentSize();									// ����� �������� ������ �������
	int GetMaxSize();										// ����� �������� ������������� ������ �������
	int ToArray(char* pluralCopy);                                        // ����� ��������� ��ﳿ �������
	int SetPlural(char* arrayOfChar, int size);				// �����, �� ���������� ������� � ������ �������
	int SetPlural(char* inputArray);					// �����, �� ���������� ������� � ����� (������ ������� � \0 � ����)
	void Print();											// ����� ������ ������� �� �����

private:

	int checkMemory(char* arr);					// ������� �������� �������� ���'�� 

	char* _arr;
	int _maxSize;
	int _currentSize;

	bool Compare(int firstSize, int secondSize); // ������� ��������� ���� �������� �������� ������

};