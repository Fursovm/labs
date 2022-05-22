#include <iostream>
#include "MyClass.h"
#define MaxSize 35
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
	if (!(_data = new char[MaxSize]))
	{
		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
		exit(0);
	}
	_currentSize = 0;
	_maxSize = MaxSize;
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
	if (strlen(data) > MaxSize)
	{
		cout << "Ємність переданої множини більша за максимальну доступну!" << endl;
		exit(0);
	}

	if (size <0 || size > strlen(data) || size > MaxSize)
	{
		cout << "Задане некоректне значення розміру множини!" << endl;
		exit(0);
	}

	if (!(_data = new char[MaxSize]))
	{
		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
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
Спрощений конструктор з параметрами
Вхід:
data-вказівник на константний рядок, передача за посиланням
*/
MyClass::MyClass(const char* data)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього
	cout << "\n\nВикликався спрощений конструктор з одним параметром - " << this << "!\n\n";
#endif 
	if (strlen(data) > MaxSize)
	{
		cout << "Ємність переданої множини більша за максимальну доступну!" << endl;
		exit(0);
	}
	if (!(_data = new char[MaxSize]))
	{
		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
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

	if (!(_data = new char[MaxSize]))
	{
		cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
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
Деструктор
*/
MyClass::~MyClass()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "\n\nВикликався деструктор-" << this << "!\n\n" << endl;
#endif 
	delete[] _data;
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
	if (strlen(data) > MaxSize)
	{
		cout << "Ємність переданої множини більша за максимальну доступну!" << endl;
		exit(0);
	}
	if (size <0 || size > strlen(data) || size > MaxSize)
	{
		cout << "Задане некоректне значення розміру множини!" << endl;
		exit(0);
	}

	if (data == nullptr)
	{
		printf("Ви не передали рядок з елементами для задання поля класу!\n");
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
			cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
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
Спрощений метод SetData для запису множини з рядка data до масиву _data
Вхід:
data-вказівник на константний рядок, передача за посиланням
Вихід:
0-якщо не був переданий рядок
1-при успішному виконанні методу
*/
int MyClass::SetData(const char* data)
{
	int size;
	if (strlen(data) > _maxSize)
	{
		cout << "Ємність переданої множини більша за максимальну доступну!" << endl;
		exit(0);
	}
	if (data == nullptr)
	{
		printf("Ви не передали рядок з елементами для задання поля класу!\n");
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
			cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
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
Метод SetCurrentSize для запису поточного розміру множини у поле _currentSize
Вхід:
currentSize-змінна, яка зберігає значення поточного розміру множини, передача за значенням
*/
void MyClass::SetCurrentSize(int currentSize)
{
	if (currentSize < 0)
	{
		cout << "Передане Вами значення для поточного розміру рядка не є коректним!\n";
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
			cout << "Не вдалося виділити пам'ять задля тимчасового розміщення множини!" << endl;
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
			cout << "Не вдалося виділити пам'ять задля розміщення множини!" << endl;
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

	_currentSize = j;
	delete[] _data;

	if (!(_data = new char[tempSize]))
	{
		cout << "Не вдалося виділити пам'ять задля тимчасового розміщення множини!" << endl;
		exit(0);
	}

	for (int i = 0; i < tempSize; i++)
	{
		_data[i] = temp._data[i];
	}
	return *this;
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