#define _CRT_SECURE_NO_WARNINGS 
#include "string.h" 
#include <iostream>
#include "Date.h" 
//#define DEBUG
using namespace std;

/*
Конструктор без параметрів
Вхід: відсутній
Вихід: відсутній
*/
Date::Date()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор без параметрів класу Date - " << this << endl << endl;
#endif 
	Set("Невідомо", "Невідомо", 0);
}

/*
Конструктор з параметрами
Вхід:
	year - рік заснування
	month - місяць заснування
	day - день заснування
Вихід: відсутній
*/
Date::Date(string year, string month, const int day)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до рядку #endif та після нього
	cout << "Викликався конструктор з параметрами класу Date - " << this << endl << endl;
#endif 
	Set(year, month, day);
}

/*
Конструктор копіювання
Вхід:
	other - константне посилання на об'єкт класу Date
Вихід: відсутній
*/
Date::Date(const Date& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі 
	cout << "Викликався конструктор копіювання класу Date - " << this << endl << endl;
#endif 
	Set(other._year, other._month, other._day);
}

/*
Геттер для року заснування
Вхід: відсутній
Вихід:
	GetYear = newYear - рік заснування
*/
string Date::GetYear()
{
	return _year;
}

/*
Геттер для місяця заснування
Вхід: відсутній
Вихід:
	GetMonth = newMonth - місяць заснування
*/
string Date::GetMonth()
{
	return _month;
}

/*
Геттер для дня заснування
Вхід: відсутній
Вихід:
	GetDay = _day - день заснування
*/
int Date::GetDay()
{
	return _day;
}

/*
Сеттер для всіх полів об'єкту класу
Вхід:
	year - рік заснування
	month - місяць заснування
	day - день заснування
Вихід: відсутній
*/
void Date::Set(string year, string month, const int day)
{
	SetYear(year);
	SetMonth(month);
	SetDay(day);
}

/*
Сеттер для року заснування
Вхід:
	year - рік заснування
Вихід: відсутній
*/
void Date::SetYear(string year)
{
	_year = year;
}

/*
Сеттер для місяця заснування
Вхід:
	month - місяць заснування
Вихід: відсутній
*/
void Date::SetMonth(string month)
{
	_month = month;
}

/*
Сеттер для дня заснування
Вхід:
	day - день заснування
Вихід: відсутній
*/
void Date::SetDay(const int day)
{
	if (day < 0 || day > 30)
		throw(exception("Ви передали некоректне значення дня!"));
	else
		_day = day;
}

/*
Метод виводу даних про дату заснування до консолі
Вхід: відсутній
Вихід: відсутній
*/
void Date::Show()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі 
	cout << "Рік: " << _year << endl;
	cout << "Місяць: " << _month << endl;
	cout << "День: " << _day << endl << endl;
#endif 
}

/*
Деструктор класу
Вхід: відсутній
Вихід: відсутній
*/
Date::~Date()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу Date - " << this << endl << endl;
#endif 
}