#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG
#include "Set.h"
const int MAXSIZE = 20;
using namespace std;


// ����������� ��� ��������� ��� ����� Set
Set::Set() {
	_maxSize = MAXSIZE;
	_arr = new char[_maxSize];
	if (!checkMemory(_arr))
	{
		exit(0);
	}
	_currentSize = 0;
}


/* ����������� � ����������� ��� ����� Set.
	����: �������� �� ����� const char* array */
Set::Set(const char* array)
{
	if (sizeUp(sizeof(array)))
	{
		int i = 0;
		while (array[i] != '\0')
			i++;
		ForArr(array, i);
	}
	else
	{
		exit(0);
	}
}


/* ����������� � ����������� ��� ����� Set.
	����: �������� �� ����� ������� char* array, ����� ������  int size*/
Set::Set(char* array, int size)
{
	_maxSize = MAXSIZE;
	int counter = 0;
	if (sizeUp(size))
		ForArr(array, size);
	else
		exit(0);
}


// ����������� ���������
Set::Set(const Set& exemplar)
{
	_currentSize = exemplar._currentSize;
	_maxSize = exemplar._maxSize;

	_arr = new char[_maxSize];

	if (checkMemory(_arr))
		ForArr(exemplar._arr, _currentSize);
}

void Set::ForArr(const char* data, int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (!(*this > data[i]))
		{
			_arr[counter] = data[i];
			counter++;
		}
	}
	_currentSize = counter;
}


// �������������� ��������� =
Set Set::operator= (const Set& exemplar)
{
	if (this == &exemplar)

		return *this;

	if (sizeUp(exemplar._currentSize))
		ForArr(exemplar._arr, exemplar._currentSize);
	else
		exit(0);
	return *this;
}


// ����� �������� �������� ���'��
int Set::checkMemory(char* arr)
{
	if (arr != NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


// ����� ������ ������� �� �����
void Set::Print()
{
	for (int i = 0; i < _currentSize; i++)
	{
		printf("%c\t", _arr[i]);
	}
	printf("\n");
}


// ����� �������� ������ �������
int Set::GetCurrentSize()
{
	return this->_currentSize;
}


// ����� �������� ������������� ������ �������
int Set::GetMaxSize()
{
	return this->_maxSize;
}


// ����� ��������� ��ﳿ �������
int Set::ToArray(char* pluralCopy) //  �� ���� ������� ������������ ��������� ��������� �� �����. ���� ����� Set

{
	if (checkMemory(pluralCopy))
	{
		for (int i = 0; i < _currentSize; i++)
		{
			pluralCopy[i] = _arr[i];
		}
		return _currentSize;
	}
	else
	{
		exit(0);
	}
}


// �����, �� ���������� ������� � ������ �������
int Set::SetPlural(char* inputArray, int size)
{
	delete[] _arr;
	_arr = nullptr;

	int counter = 0;
	if (sizeUp(size))
	{
		ForArr(inputArray, size);
		return 1;
	}
	else
		exit(0);

}


// �����, �� ���������� ������� � ����� (������ ������� � \0 � ����)
int Set::SetPlural(char* inputArray)
{
	delete[] _arr;
	_arr = new char[_maxSize];
	int counter = 0;
	if (!sizeUp(sizeof(inputArray)))
		return 0;
	int i = 0;
	while (inputArray[i] != '\0')
		i++;
	ForArr(inputArray, i);
	return 1;
}

// �������, �� ������ ������������ �������� ����� ������ ���, ��� _maxSize > demandSize 
int Set::sizeUp(int demandSize)
{
	if ((_maxSize >= demandSize) && (checkMemory(_arr)))
	{
		_currentSize = demandSize;
		return 1;
	}
	else if ((_maxSize < demandSize) && (_currentSize != 0))
	{
		char* duplicate = NULL;
		ToArray(duplicate);

		_maxSize = int((demandSize / MAXSIZE) + 1) * MAXSIZE;

		if (checkMemory(_arr))
		{
			delete[] _arr;
		}
		_arr = new char[_maxSize];
		if (!checkMemory(_arr))
			return 0;
		_currentSize = demandSize;

		for (int i = 0; i < _currentSize - 1; i++)
		{
			_arr[i] = duplicate[i];
		}
		delete[] duplicate;
	}
	else
	{
		_maxSize = int((demandSize / MAXSIZE) + 1) * MAXSIZE;

		if (checkMemory(_arr))
		{
			delete[] _arr;
		}
		_arr = new char[_maxSize];
		if (!checkMemory(_arr))
			return 0;
		_currentSize = demandSize;

	}
	return 1;

}

//������� ��������� �������� ���� ������
bool Set::Compare(int firstSize, int secondSize)
{
	if (firstSize < secondSize)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//�������������� ��������� + (��'������� ������)
Set Set::operator+ (const Set& other)
{
	Set temp;

	int size = _currentSize;
	for (int i = 0; i < other._currentSize; i++)
	{
		bool flag = false;
		for (int j = 0; j < size; j++)
		{
			if (_arr[j] == other._arr[i])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			other._arr[i] + *this;
			flag = false;
		}
	}

	return *this;
}


//�������������� ��������� + (��������� �������� �� �������)
Set operator+(char element, Set& other)
{
	if (other._arr == NULL)
	{
		return other;
	}

	if (other.sizeUp(other._currentSize + 1))
	{
		char* data = NULL;
		other.ToArray(data);
		char* newData = new char[other.GetCurrentSize() + 1];
		if (!newData)
		{
			exit(0);
		}
		for (int i = 0; i < other.GetCurrentSize(); i++)
		{
			newData[i] = data[i];
		}
		newData[other.GetCurrentSize()] = element;
		other.SetPlural(newData, other.GetCurrentSize() + 1);
		delete[] newData;
		delete[] data;
	}
	else
	{
		exit(0);
	}
	return other;
}

//�������������� ��������� == (�������� ������ �� ������)
int Set::operator==(const Set& other)
{
	int counter = 0;
	if (_currentSize == other._currentSize)
	{
		for (int i = 0; i < _currentSize; i++)
		{
			if (!(* other._arr > _arr[i]))
				counter++;
		}

		if (counter == _currentSize)
			return 1;
		else
			return 0;
	}
	else
	{
		return 0;
	}
}

//�������������� ��������� > (�������� ������� �� ������������ � ������)
int Set::operator> (char symbol)
{
	for (int i = 0; i < _currentSize; i++)
	{
		if (_arr[i] == symbol)
		{
			return 1;
		}
	}
	return 0;
}

// ����������
Set::~Set()
{
	delete[] _arr;
}
