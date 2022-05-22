class MyClass
{
public:
	MyClass(); //конструктор за замовчуванням
	MyClass(const char* data, int size); //конструктор з параметрами
	MyClass(const char* data); //спрощений конструктор з параметрами
	MyClass(const MyClass& other); //конструктор копіювання
	~MyClass(); //деструктор
	int SetData(const char* data, int size); //сеттер для множини
	int SetData(const char* data); //спрощений сеттер для множини
	void SetCurrentSize(int currentSize); //сеттер для поточного розміру
	char* GetData(); //геттер для множини
	int GetCurrentSize(); //геттер для розміру множини
	int GetMaxSize(); //геттер для максимального розміру множини
	int Print(); //вивід множини
	MyClass operator-(char element); //оператор для видалення елементів заданих з множини(2 варіант)
	int operator<(const MyClass& other); //оператор для порівняння розмірів множин
	MyClass operator*(const MyClass& other); //оператор для отримання множини-перетину двох підмножин, з якими проводиться операція
	MyClass operator=(const MyClass& other); //оператор присвоювання для повного копіювання полів іншого об'єкту класу
private:
	char* _data; //покажчик на початок рядка
	int _currentSize; //поточний розмір
	int _maxSize; //максимальний розмір рядка

	bool DataCheck(const MyClass& other); //для перевірки на те, чи поле-покажчик елементу класу вказує на ділянку в пам'яті, чи на NULL-pointer
	bool Compare(int firstSize, int secondSize); //для порівняння двох поточних ємностей множин
};
