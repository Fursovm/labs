#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG
#include "plural.h"
using namespace std;


// Конструктор без параметрів для класу Plural
Plural::Plural() {
	_maxSize = MAXSIZE;
	_arr = new char[_maxSize];
	if (!checkMemory(_arr))
	{
		exit(0);
	}
	_currentSize = 0;

}


/* Конструктор з параметрами для класу Plural.
	Вхід: покажчик на рядок const char* array */
Plural::Plural(const char* array)
{
	this->_maxSize = MAXSIZE;
	int counter = 0;
	if (sizeIncrease(sizeof(array)))
	{
		int i = 0;
		while (array[i] != '\0')
		{
			if (!((Plural)*this > array[i]))
			{
				_arr[counter] = array[i];
				counter++;
			}
			i++;
		}
		this->_currentSize = counter;
	}
	else { exit(0); }
}


/* Конструктор з параметрами для класу Plural.
	Вхід: покажчик на масив символів char* array, розмір масиву  int size*/
Plural::Plural(char* array, int size)
{

	this->_maxSize = MAXSIZE;
	int counter = 0;
	if (sizeIncrease(size))
	{
		for (int i = 0; i < size; i++)
		{
			if (!((Plural)*this > array[i]))
			{
				_arr[counter] = array[i];
				counter++;
			}
		}
		this->_currentSize = counter;
	}
	else { exit(0); }
}


// Конструктор копіювання
Plural::Plural(const Plural& exemplar)
{
	_currentSize = exemplar._currentSize;
	_maxSize = exemplar._maxSize;

	_arr = new char[_maxSize];

	if (checkMemory(_arr))
	{
		for (int i = 0; i < _currentSize; i++)
		{
			if (_arr[i] != NULL) _arr[i] = exemplar._arr[i];
		}
	}

}


// Перевантаження оператора =
Plural Plural::operator= (const Plural& exemplar)
{
	if (this == &exemplar) return *this;

	if (this->sizeIncrease(exemplar._currentSize))
	{
		for (int i = 0; i < exemplar._currentSize; i++)
		{
			this->_arr[i] = exemplar._arr[i];
		}
	}
	else
	{
		exit(0);
	}
	return *this;
}


// Метод перевірки виділення пам'яті
int Plural::checkMemory(char* arr)
{
	if (arr != NULL)
	{
		return 1;
	}
	else { return 0; }
}


// Метод виводу множини на екран
void Plural::Print()
{
	for (int i = 0; i < _currentSize; i++)
	{
		printf("%c\t", _arr[i]);
	}
	printf("\n");
}


// Метод отриманя розміру множини
int Plural::GetCurrentSize()
{
	return this->_currentSize;
}


// Метод отриманя максимального розміру множини
int Plural::GetMaxSize()
{
	return this->_maxSize;
}


// Метод отримання копії множини
char* Plural::ToArray() // из этой функции перегрузить оператора присваивания и возвращать объект класса Plural
{
	char* pluralCopy;
	pluralCopy = new char[this->_currentSize];


	if (checkMemory(pluralCopy))
	{
		for (int i = 0; i < _currentSize; i++)
		{
			pluralCopy[i] = this->_arr[i];
		}
		return pluralCopy;
	}
	else
	{
		return nullptr;
	}
}


// Метод, що встановлює множину з масиву символів
int Plural::SetPlural(char* inputArray, int size)
{
	delete[] _arr;
	_arr = nullptr;
	//_arr = new char[size];

	int counter = 0;
	if (!sizeIncrease(size)) return 0;
	for (int i = 0; i < size; i++)
	{
		if (!((Plural)*this > inputArray[i]))
		{
			_arr[counter] = inputArray[i];
			counter++;
		}
	}
	this->_currentSize = counter;
	return 1;

}


// Метод, що встановлює множину з рядка (масиву символів з \0 в кінці)
int Plural::SetPlural(const char* inputArray)
{
	delete[] _arr;
	_arr = new char[_maxSize];
	int counter = 0;
	if (!sizeIncrease(sizeof(inputArray))) return 0;
	int i = 0;
	while (inputArray[i] != '\0')
	{
		if (!((Plural)*this > inputArray[i]))
		{
			_arr[counter] = inputArray[i];
			counter++;
		}
		i++;
	}
	this->_currentSize = counter;
	return 1;
}

// Функція, що збільшує максимальной можливий розмір масиву так, щоб _maxSize > demandSize 
int Plural::sizeIncrease(int demandSize)
{
	if ((_maxSize > demandSize) && (checkMemory(_arr)))
	{
		_currentSize = demandSize;
		return 1;
	}
	else
	{
		do
		{
			_maxSize += MAXSIZE;
		} while (_maxSize < demandSize);

		if (checkMemory(_arr)) { delete[] _arr; }
		_arr = new char[_maxSize];
		if (!checkMemory(_arr)) return 0;
		_currentSize = demandSize;

	}
	return 1;

}

//Функція порівняння ємностей двох множин
bool Plural::Compare(int firstSize, int secondSize)
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

//Перевантаження оператора + (об'єднання множин)
Plural Plural::operator+ (const Plural& other)
{
	Plural temp;

	int size = this->_currentSize;
	for (int i = 0; i < other._currentSize; i++)
	{
		bool flag = false;
		for (int j = 0; j < size; j++)
		{
			if (this->_arr[j] == other._arr[i])
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

//Перевантаження оператора + (додавання елемента до множини)
Plural operator+(char element, Plural& other)
{
	if (other._arr == NULL)
	{
#ifdef DEBUG
		cout << "Рядок, до якого бажаєте додати елемент, не був створений!" << endl;
#endif
		return other;
	}

	if (other.GetCurrentSize() + 1 <= other.GetMaxSize())
	{
		char* data = other.ToArray();
		char* newData = new char[other.GetCurrentSize() + 1];
		if (!newData)
		{
#ifdef DEBUG
			cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
#endif
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
		char* data = other.ToArray();
		int size = other.GetCurrentSize();
		delete[] other._arr;
		other._arr = new char[size + MAXSIZE];

		if (!other._arr)
		{
#ifdef DEBUG
			cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
#endif
			exit(0);
		}

		for (int i = 0; i < other.GetCurrentSize(); i++)
		{
			other._arr[i] = data[i];
		}

		other._arr[other.GetCurrentSize()] = element;
		delete[] data;
	}
	return other;
}

//Перевантаження оператора == (перевірки множин на рівність)
int Plural::operator==(const Plural& other)
{
	int counter = 0;
	if (this->_currentSize == other._currentSize)
	{
		for (int i = 0; i < this->_currentSize; i++)
		{
			for (int j = 0; j < this->_currentSize; j++)
			{
				if (this->_arr[i] == other._arr[j])
				{
					counter++;
					break;
				}
			}
		}

		if (counter == this->_currentSize)
			return 1;
		else
			return 0;
	}
	else
	{
		return 0;
	}
}

//Перевантаження оператора > (перевірка символа на приналежність в множині)
int Plural::operator> (char symbol)
{
	for (int i = 0; i < _currentSize; i++)
	{
		if (_arr[i] == symbol) { return 1; }
	}
	return 0;
}

// Деструктор
Plural::~Plural()
{
	delete[] _arr;
}
