#include <iostream>
#include "MyClass.h"
#define MAXSIZE 35
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
	if (!(_data = new char[MAXSIZE]))
	{
		cout << "�� ������� ������� ���'��� ����� ��������� �������!" << endl;
		exit(0);
	}
	_currentSize = 0;
	_maxSize = MAXSIZE;
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
	if (strlen(data) != size)
	{
		exit(0);
	}

	if (sizeUp(size))
	{
		for (int i = 0; i < size; i++)
		{
			_data[i] = data[i];
		}
	}
	else
		exit(0);
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
	int size = strlen(data);
	if (sizeUp(size))
	{
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
	}
	else
		exit(0);
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
	_data = new char[_maxSize];

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
	//delete[] _data;
}

// �������, �� ������ ������������ �������� ����� ������
int MyClass::sizeUp(int demandSize)
{
	char* duplicate = NULL;
	if (_maxSize >= demandSize)
	{
		_currentSize = demandSize;
		return 1;
	}
	else if ((_maxSize < demandSize) && (_currentSize != 0))
	{
		GetData(duplicate);
		_maxSize = int((demandSize / MAXSIZE) + 1) * MAXSIZE;

		delete _data;
		_data = new char[_maxSize];
		if (_data == NULL)
			return 0;
		_currentSize = demandSize;

		for (int i = 0; i < _currentSize - 1; i++)
		{
			_data[i] = duplicate[i];
		}
		delete[] duplicate;
	}
	else
	{
		_maxSize = int((demandSize / MAXSIZE) + 1) * MAXSIZE;

		delete[] _data;
		_data = new char[_maxSize];
		_currentSize = demandSize;
	}
	return 1;

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
int MyClass::GetData(char* data)
{
	if (data != NULL)
		delete[] data;

	data = new char[_maxSize];

	if (_currentSize != 0)
	{
		for (int i = 0; i < _currentSize; i++)
		{
			data[i] = _data[i];
		}
		return _currentSize;
	}
	else
	{
		return 0;
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
	if (strlen(data) != size)
		return 0;

	if (sizeUp(size))
	{
		for (int i = 0; i < size; i++)
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
		return 1;
	}
	else
		exit(0);
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
	if (data == nullptr)
		return 0;

	if (_data != nullptr)
		delete[] _data;

	int size = strlen(data);
	if (sizeUp(size))
	{
		for (int i = 0; i < size; i++)
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
		return 1;
	}
	else
		exit(0);
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
		exit(0);
	}

	if (sizeUp(currentSize))
	{
		if (currentSize > _currentSize && currentSize <= _maxSize)
		{
			for (int i = _currentSize; i < currentSize; i++)
			{
				_data[i] = ' ';
			}
		}
	}
	else
		exit(0);
}

//�������� ��� ��������� �������� ������� � �������
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
	int tempMaxSize = 0;
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
		tempMaxSize = other._maxSize;
	}
	else
	{
		tempSize = _currentSize;
		tempMaxSize = _maxSize;
	}

	if (!(temp._data = new char[tempMaxSize]))
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

	for (int i = 0; i < tempSize; i++)
	{
		_data[i] = temp._data[i];
	}
	temp._currentSize = j;

	return temp;
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
