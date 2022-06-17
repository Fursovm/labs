#include <iostream>
#include "MyClass.h"
#define MAXSIZE 35
#define DEBUG
using namespace std;

/*
Конструктор без параметрів
*/
MyClass::MyClass()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього
	cout << "\n\nВикликався конструктор за замовчуванням - " << this << "!\n\n";
#endif 
	if (!(_data = new char[MAXSIZE]))
	{
		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
		exit(0);
	}
	_currentSize = 0;
	_maxSize = MAXSIZE;
}

/*
Конструктор з параметрами
Вхід:
data-вказівник на константний рядок, передача за посиланням
size-змінна, яка зберігає значення розміру множини, передача за значенням
*/
MyClass::MyClass(const char* data, int size)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього
	cout << "\n\nВикликався конструктор з параметрами-" << this << "!\n\n";
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
Спрощений конструктор з параметрами
Вхід:
data-вказівник на константний рядок, передача за посиланням
*/
MyClass::MyClass(const char* data)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього
	cout << "\n\nВикликався спрощений конструктор з одним параметром - " << this << "!\n\n";
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
Конструктор копіювання
Вхід:
other-змінна типу класу, передача за посиланням
*/
MyClass::MyClass(const MyClass& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього
	cout << "\n\nВикликався конструктор копіювання-" << this << "!\n\n";
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
Деструктор
*/
MyClass::~MyClass()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "\n\nВикликався деструктор-" << this << "!\n\n" << endl;
#endif 
	//delete[] _data;
}

// Функція, що збільшує максимальной можливий розмір масиву
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
Метод Print для виводу в консоль множини
Вихід:
1-при успішному виконанні методу
0-у випадку, якщо множина для друку не була створена
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
		cout << "Рядок для друку не був створений!" << endl;
		return 0;
	}
}


/*
Метод GetData для отримання значення поля _data об'єкту класу
Вихід:
Вказівник на рядок з записаною множиною в ньому або вказівник на nullpointer
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
Метод GetCurrentSize для отримання значення поля _currentSize об'єкту класу
Вихід:
Поточна ємність множини, яка записана в полі _currentSize об'єкту класу
*/
int MyClass::GetCurrentSize()
{
	return _currentSize;
}

/*
Метод GetMaxSize для отримання значення поля _maxSize об'єкту класу
Вихід:
Максимальна ємність множини, яка записана в полі _maxSize об'єкту класу
*/
int MyClass::GetMaxSize()
{
	return _maxSize;
}


/*
Метод SetData для запису множини з рядка data до масиву _data
Вхід:
data-вказівник на константний рядок, передача за посиланням
size-кількість елементів переданої множини, передача за значенням
Вихід:
0-якщо не був переданий рядок
1-при успішному виконанні методу
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
Спрощений метод SetData для запису множини з рядка data до масиву _data
Вхід:
data-вказівник на константний рядок, передача за посиланням
Вихід:
0-якщо не був переданий рядок
1-при успішному виконанні методу
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
Метод SetCurrentSize для запису поточного розміру множини у поле _currentSize
Вхід:
currentSize-змінна, яка зберігає значення поточного розміру множини, передача за значенням
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

//оператор для видалення елементів заданих з множини
MyClass MyClass::operator-(char element)
{
	if (_data == nullptr)
	{
		cout << "Рядок, з якого бажаєте видалити елемент, не був створений!" << endl;
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
Перевантаження оператора порівняння задля порівняння ємностей двох множин
Вхід:
other-змінна типу класу, передача за посиланням
Вихід:
-2-якщо одна з множин не існує
1-якщо перша множина менша за другу
0-якщо перша множина не менша за другу
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
Перевантаження оператора "*" задля утворення множини-перетину двох переданих підмножин
Вхід:
other-змінна типу класу, передача за посиланням
Вихід:
Змінна типу класу
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
		cout << "Не вдалося виділити пам'ять задля тимчасового розміщення множини!" << endl;
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
Перевантаження оператора присвоювання задля утворення копії вже існуючого об'єкту класу
Вхід:
other-змінна типу класу, передача за посиланням
Вихід:
Змінна типу класу
*/
MyClass MyClass::operator=(const MyClass& other)
{
	if (_data != nullptr)
	{
		delete[] _data;
	}

	if (!(_data = new char[other._currentSize]))
	{
		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
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
Функція для перевірки того, чи поле переданого об'єкту класу вказує на ділянку пам'яті з множиною
Вхід:
other-змінна типу класу, передача за посиланням
Вихід:
0-якщо поле переданого об'єкту класу не вказує на ділянку пам'яті з множиною
1-якщо поле переданого об'єкту класу вказує на ділянку пам'яті з множиною
*/
bool MyClass::DataCheck(const MyClass& other)
{
	if (other._data == nullptr)
	{
		cout << "Рядок для порівняння не існує!" << endl;
		return 0;
	}
	else
	{
		return 1;
	}
}

/*
Функція порівняння ємностей двох множин
Вхід:
firstSize-ємність першої множини для порівняння, передача за значенням
secondSize-ємність другої множини для порівняння, передача за значенням
Вихід:
1-якщо перша множина менша за другу
0-якщо перша множина не менша за другу
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
