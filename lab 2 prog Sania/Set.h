#pragma once
class Set
{

public:

	Set();												// Конструктор без параметров для класу Set
	Set(char* array, int size);							// Конструктор з параметрами для класу Set
	Set(const char* array);								// Конструктор з параметрами(рядком символів) для класу Set
	Set(const Set& exemplar);							// Конструктор копіювання
	~Set();												// Деструктор

	Set operator+ (const Set& other);					// Перевантаження оператора + (об'єднання множин)
	friend Set operator+(char element, Set& other);    // Перевантаження оператора + (додавання елемента до множини)
	int operator==(const Set& other);					// Перевантаження оператора ==
	Set operator= (const Set& exemplar);				// Перевантаження оператора =
	int operator> (char symbol);

	int sizeUp(int demandSize);						// Функція, що збільшує максимальной можливий розмір масиву так, щоб _maxSize > demandSize 
	void ForArr(const char* data, int size);
	int GetCurrentSize();									// Метод отриманя розміру множини
	int GetMaxSize();										// Метод отриманя максимального розміру множини
	int ToArray(char* pluralCopy);                                        // Метод отримання копії множини
	int SetPlural(char* arrayOfChar, int size);				// Метод, що встановлює множину з масиву символів
	int SetPlural(char* inputArray);					// Метод, що встановлює множину з рядка (масиву символів з \0 в кінці)
	void Print();											// Метод виводу множини на екран

private:

	int checkMemory(char* arr);					// Функція перевірки виділення пам'яті 

	char* _arr;
	int _maxSize;
	int _currentSize;

	bool Compare(int firstSize, int secondSize); // Функція порівняння двох поточних ємностей множин

};