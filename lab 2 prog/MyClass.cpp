#include <iostream>
#include "MyClass.h"
#define MaxSize 35
#define DEBUG
using namespace std;

/*
����������� ��� ���������
*/
MyClass::MyClass()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� �����
	cout << "\n\n���������� ����������� �� ������������� - " << this << "!\n\n";
#endif 
	if (!(_data = new char[MaxSize]))
	{
		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
		exit(0);
	}
	_currentSize = 0;
	_maxSize = MaxSize;
}

/*
����������� � �����������
����:
data-�������� �� ����������� �����, �������� �� ����������
size-�����, ��� ������ �������� ������ �������, �������� �� ���������
*/
MyClass::MyClass(const char* data, int size)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� �����
	cout << "\n\n���������� ����������� � �����������-" << this << "!\n\n";
#endif 
	if (strlen(data) > MaxSize)
	{
		cout << "������ �������� ������� ����� �� ����������� ��������!" << endl;
		exit(0);
	}

	if (size <0 || size > strlen(data) || size > MaxSize)
	{
		cout << "������ ���������� �������� ������ �������!" << endl;
		exit(0);
	}

	if (!(_data = new char[MaxSize]))
	{
		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
		exit(0);
	}

	for (int i = 0; i < size; i++)
	{
		_data[i] = data[i];
	}

	_currentSize = size;
	_maxSize = MaxSize;
}

/*
��������� ����������� � �����������
����:
data-�������� �� ����������� �����, �������� �� ����������
*/
MyClass::MyClass(const char* data)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� �����
	cout << "\n\n���������� ��������� ����������� � ����� ���������� - " << this << "!\n\n";
#endif 
	if (strlen(data) > MaxSize)
	{
		cout << "������ �������� ������� ����� �� ����������� ��������!" << endl;
		exit(0);
	}
	if (!(_data = new char[MaxSize]))
	{
		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
		exit(0);
	}

	_currentSize = strlen(data);
	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = data[i];
	}

	for (int i = 0; i < _currentSize; i++)
	{
		for (int j = i + 1; j < _currentSize; j++)
		{
			if (_data[i] == _data[j])
			{
				for (int k = j; k < _currentSize; k++)
				{
					_data[k] = _data[k + 1];
				}
				j--;
				_currentSize--;
			}
		}
	}

	_maxSize = MaxSize;
}

/*
����������� ���������
����:
other-����� ���� �����, �������� �� ����������
*/
MyClass::MyClass(const MyClass& other)
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� �����
	cout << "\n\n���������� ����������� ���������-" << this << "!\n\n";
#endif 
	_currentSize = other._currentSize;
	_maxSize = other._maxSize;

	if (!(_data = new char[MaxSize]))
	{
		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
		exit(0);
	}

	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = other._data[i];
	}

	for (int i = 0; i < _currentSize; i++)
	{
		for (int j = i + 1; j < _currentSize; j++)
		{
			if (_data[i] == _data[j])
			{
				for (int k = j; k < _currentSize; k++)
				{
					_data[k] = _data[k + 1];
				}
				j--;
				_currentSize--;
			}
		}
	}
}


/*
����������
*/
MyClass::~MyClass()
{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� �� ���� #endif 
	cout << "\n\n���������� ����������-" << this << "!\n\n" << endl;
#endif 
	delete[] _data;
}

/*
����� Print ��� ������ � ������� �������
�����:
1-��� �������� �������� ������
0-� �������, ���� ������� ��� ����� �� ���� ��������
*/
int MyClass::Print()
{
	if (_data != nullptr)
	{
		cout << "{";
		for (int i = 0; i < _currentSize; i++)
		{
			if (i == _currentSize - 1)
			{
				cout << _data[i];
			}
			else
			{
				cout << "'" << _data[i] << "'";
			}
		}
		cout << "}";
		return 1;
	}
	else
	{
		cout << "����� ��� ����� �� ��� ���������!" << endl;
		return 0;
	}
}


/*
����� GetData ��� ��������� �������� ���� _data ��'���� �����
�����:
�������� �� ����� � ��������� �������� � ����� ��� �������� �� nullpointer
*/
char* MyClass::GetData()
{
	if (_currentSize != 0)
	{
		char* temp = new char[_currentSize];
		for (int i = 0; i < _currentSize; i++)
		{
			temp[i] = _data[i];
		}
		return temp;
	}
	else
	{
		return NULL;
	}
}

/*
����� GetCurrentSize ��� ��������� �������� ���� _currentSize ��'���� �����
�����:
������� ������ �������, ��� �������� � ��� _currentSize ��'���� �����
*/
int MyClass::GetCurrentSize()
{
	return _currentSize;
}

/*
����� GetMaxSize ��� ��������� �������� ���� _maxSize ��'���� �����
�����:
����������� ������ �������, ��� �������� � ��� _maxSize ��'���� �����
*/
int MyClass::GetMaxSize()
{
	return _maxSize;
}


/*
����� SetData ��� ������ ������� � ����� data �� ������ _data
����:
data-�������� �� ����������� �����, �������� �� ����������
size-������� �������� �������� �������, �������� �� ���������
�����:
0-���� �� ��� ��������� �����
1-��� �������� �������� ������
*/
int MyClass::SetData(const char* data, int size)
{
	if (strlen(data) > MaxSize)
	{
		cout << "������ �������� ������� ����� �� ����������� ��������!" << endl;
		exit(0);
	}
	if (size <0 || size > strlen(data) || size > MaxSize)
	{
		cout << "������ ���������� �������� ������ �������!" << endl;
		exit(0);
	}

	if (data == nullptr)
	{
		printf("�� �� �������� ����� � ���������� ��� ������� ���� �����!\n");
		return 0;
	}
	else
	{
		if (_data != nullptr)
		{
			delete[] _data;
		}

		if (!(_data = new char[MaxSize]))
		{
			cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
			exit(0);
		}

		for (int i = 0; i < size; i++)
		{
			_data[i] = data[i];
		}
	}
	_currentSize = size;

	for (int i = 0; i < _currentSize; i++)
	{
		for (int j = i + 1; j < _currentSize; j++)
		{
			if (_data[i] == _data[j])
			{
				for (int k = j; k < _currentSize; k++)
				{
					_data[k] = _data[k + 1];
				}
				j--;
				_currentSize--;
			}
		}
	}
	return 1;
}

/*
��������� ����� SetData ��� ������ ������� � ����� data �� ������ _data
����:
data-�������� �� ����������� �����, �������� �� ����������
�����:
0-���� �� ��� ��������� �����
1-��� �������� �������� ������
*/
int MyClass::SetData(const char* data)
{
	int size;
	if (strlen(data) > _maxSize)
	{
		cout << "������ �������� ������� ����� �� ����������� ��������!" << endl;
		exit(0);
	}
	if (data == nullptr)
	{
		printf("�� �� �������� ����� � ���������� ��� ������� ���� �����!\n");
		return 0;
	}
	else
	{
		if (_data != nullptr)
		{
			delete[] _data;
		}

		if (!(_data = new char[_maxSize]))
		{
			cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
			exit(0);
		}

		size = strlen(data);
		for (int i = 0; i < size; i++)
		{
			_data[i] = data[i];
		}
	}
	_currentSize = size;

	for (int i = 0; i < _currentSize; i++)
	{
		for (int j = i + 1; j < _currentSize; j++)
		{
			if (_data[i] == _data[j])
			{
				for (int k = j; k < _currentSize; k++)
				{
					_data[k] = _data[k + 1];
				}
				j--;
				_currentSize--;
			}
		}
	}
	return 1;
}

/*
����� SetCurrentSize ��� ������ ��������� ������ ������� � ���� _currentSize
����:
currentSize-�����, ��� ������ �������� ��������� ������ �������, �������� �� ���������
*/
void MyClass::SetCurrentSize(int currentSize)
{
	if (currentSize < 0)
	{
		cout << "�������� ���� �������� ��� ��������� ������ ����� �� � ���������!\n";
		exit(0);
	}

	if (currentSize > _currentSize && currentSize <= MaxSize)
	{
		for (int i = _currentSize; i < currentSize; i++)
		{
			_data[i] = ' ';
		}
	}

	if (currentSize > MaxSize)
	{
		char* tempData;
		if (!(tempData = new char[_currentSize]))
		{
			cout << "�� ������� ������� ���'��� ����� ����������� ��������� �������!" << endl;
			exit(0);
		}

		for (int i = 0; i < _currentSize; i++)
		{
			tempData[i] = _data[i];
		}
		_maxSize = currentSize;
		delete[] _data;

		if (!(_data = new char[_maxSize]))
		{
			cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
			exit(0);
		}

		for (int i = 0; i < _currentSize; i++)
		{
			_data[i] = tempData[i];
		}
		delete[] tempData;
		for (int i = _currentSize; i < _maxSize; i++)
		{
			_data[i] = ' ';
		}
	}

	_currentSize = currentSize;
}

MyClass MyClass::operator-(char element)
{
	if (_data == nullptr)
	{
		cout << "�����, � ����� ������ �������� �������, �� ��� ���������!" << endl;
		return *this;
	}

	for (int i = 0; i < _currentSize; i++)
	{
		if (_data[i] == element)
		{
			for (int j = i; j < _currentSize; j++)
			{
				_data[j] = _data[j + 1];
			}
			_currentSize--;
			return *this;
		}
	}
	return *this;
}

/*
�������������� ��������� ��������� ����� ��������� �������� ���� ������
����:
other-����� ���� �����, �������� �� ����������
�����:
-2-���� ���� � ������ �� ����
1-���� ����� ������� ����� �� �����
0-���� ����� ������� �� ����� �� �����
*/
int MyClass::operator<(const MyClass& other)
{
	if (!DataCheck(other))
	{
		return -2;
	}

	if (!DataCheck(*this))
	{
		return -2;
	}
	return Compare(_currentSize, other._currentSize);
}

/*
�������������� ��������� "*" ����� ��������� �������-�������� ���� ��������� ��������
����:
other-����� ���� �����, �������� �� ����������
�����:
����� ���� �����
*/
MyClass MyClass::operator*(const MyClass& other)
{
	MyClass temp;
	int tempSize = 0;
	int j = 0;

	if (!DataCheck(other))
	{
		return temp;
	}

	if (!DataCheck(*this))
	{
		return temp;
	}

	if (_currentSize > other._currentSize)
	{
		tempSize = other._currentSize;
	}
	else
	{
		tempSize = _currentSize;
	}

	if (!(temp._data = new char[tempSize]))
	{
		cout << "�� ������� ������� ���'��� ����� ����������� ��������� �������!" << endl;
		exit(0);
	}

	for (int i = 0; i < tempSize; i++)
	{
		if (other._data[i] == _data[i])
		{
			temp._data[j] = _data[i];
			j++;
		}
	}

	_currentSize = j;
	delete[] _data;

	if (!(_data = new char[tempSize]))
	{
		cout << "�� ������� ������� ���'��� ����� ����������� ��������� �������!" << endl;
		exit(0);
	}

	for (int i = 0; i < tempSize; i++)
	{
		_data[i] = temp._data[i];
	}
	return *this;
}

/*
�������������� ��������� ������������ ����� ��������� ��ﳿ ��� ��������� ��'���� �����
����:
other-����� ���� �����, �������� �� ����������
�����:
����� ���� �����
*/
MyClass MyClass::operator=(const MyClass& other)
{
	if (_data != nullptr)
	{
		delete[] _data;
	}

	if (!(_data = new char[other._currentSize]))
	{
		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
		exit(0);
	}
	_currentSize = other._currentSize;
	_maxSize = other._maxSize;
	for (int i = 0; i < _currentSize; i++)
	{
		_data[i] = other._data[i];
	}
	return *this;
}
/*
������� ��� �������� ����, �� ���� ���������� ��'���� ����� ����� �� ������ ���'�� � ��������
����:
other-����� ���� �����, �������� �� ����������
�����:
0-���� ���� ���������� ��'���� ����� �� ����� �� ������ ���'�� � ��������
1-���� ���� ���������� ��'���� ����� ����� �� ������ ���'�� � ��������
*/
bool MyClass::DataCheck(const MyClass& other)
{
	if (other._data == nullptr)
	{
		cout << "����� ��� ��������� �� ����!" << endl;
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
������� ��������� �������� ���� ������
����:
firstSize-������ ����� ������� ��� ���������, �������� �� ���������
secondSize-������ ����� ������� ��� ���������, �������� �� ���������
�����:
1-���� ����� ������� ����� �� �����
0-���� ����� ������� �� ����� �� �����
*/
bool MyClass::Compare(int firstSize, int secondSize)
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