#include <iostream>
using namespace std;

class Date
{
public: //компоненти класу, до яких наданий публічний доступ
	Date(); //конструктор без параметрів
	Date(string year, string month, const int day); //конструктор з параметрами
	Date(const Date& other); //конструктор копіювання
	Date(Date&&) noexcept = default; //конструктор переміщення за замовчуванням
	Date& operator=(Date&&) = default; //переміщення за допомогою оператора присвоювання за замовчуванням
	Date& operator=(const Date&) = default; //копіювання за допомогою оператора присвоювання за замовчуванням
	string GetYear(); //геттер для року без зазначення кількості елементів для запису
	string GetMonth(); //геттер для місяця без зазначеноњ кількості елементів для запису
	int GetDay(); //геттер для дня
	void Set(string year, string month, const int day); //сеттер для всіх полів
	void SetYear(string year); //сеттер для року
	void SetMonth(string month); //сеттер для року
	void SetDay(const int day); //сеттер для року
	void Show(); //вивід даних про дату до консолі
	~Date(); //деструктор
protected: //компоненти класу, до яких захищений доступ
	string _year, //рік
		_month; //місяць
	int _day; //день
};