class Set
{
public:
	Set(); //конструктор за замовчуванням
	Set(const char* data, int size); //конструктор з параметрами
	Set(const char* data); //спрощений конструктор з параметрами
	Set(const Set& other); //конструктор копіювання
	~Set(); //деструктор
	int SetData(const char* data, int size); //сеттер для множини
	int SetData(const char* data); //спрощений сеттер для множини
	void SetCurrentSize(int currentSize); //сеттер для поточного розміру
	char* GetData(); //геттер для множини
	int GetCurrentSize(); //геттер для розміру множини
	int GetMaxSize(); //геттер для максимального розміру множини
	int Print(); //вивід множини
	//friend Set operator-(Set& other, char element); //оператор для видалення елементів заданих з множини(1 варіант)
	Set operator-(char element); //оператор для видалення елементів заданих з множини(2 варіант)
	int operator<(const Set& other); //оператор для порівняння розмірів множин
	Set operator*(const Set& other); //оператор для отримання множини-перетину двох підмножин, з якими проводиться операція
	Set operator=(const Set& other); //оператор присвоювання для повного копіювання полів іншого об'єкту класу
private:
	char* _data; //покажчик на початок рядка
	int _currentSize; //поточний розмір
	int _maxSize; //максимальний розмір рядка

	bool DataCheck(const Set& other); //для перевірки на те, чи поле-покажчик елементу класу вказує на ділянку в пам'яті, чи на NULL-pointer
	bool Compare(int firstSize, int secondSize); //для порівняння двох поточних ємностей множин
};
