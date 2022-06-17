#define _CRT_SECURE_NO_WARNINGS 
#include "string.h" 
#include <iostream>
#include <vector>
#include "Firm.h"
//#define DEBUG
using namespace std;

/*
Конструктор без параметрів
Вхід: відсутній
Вихід: відсутній
*/
Firm::Firm()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор без параметрів класу Enterprice - " << this << endl << endl;
#endif 
	_proceeds = 0;
}

/*
Конструктор з параметрами
Вхід:
	items - відділи корпорації
	createdAt - дата заснування
	name - назва корпорації
	chiefExecutiveOfficer - CEO корпорації
	proceeds - прибуток корпорації
Вихід: відсутній
*/
Firm::Firm(vector<Department> items, Date& createdAt, string name, string chiefExecutiveOfficer, double proceeds)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор з параметрами класу Enterprice - " << this << endl << endl;
#endif 
	Set(items, createdAt, name, chiefExecutiveOfficer, proceeds);
}

/*
Конструктор копіювання
Вхід:
	other - константне посилання на об'єкт класу Enterprise
Вихід: відсутній
*/
Firm::Firm(const Firm& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
	cout << "Викликався конструктор копіювання класу Enterprice - " << this << endl << endl;
#endif
	Set(other._items, *const_cast<Date*>(&other._createdAt), other._name, other._chiefExecutiveOfficer, other._proceeds);
}

/*
Метод для отримання адреси конкретного відділу
Вхід:
	numOfDep - номер відділу, адресу на який користувач бажає отримати
Вихід:
	GetDepartment = &_items[numOfDep - 1] - посилання на конкретний відділ
*/
Department* Firm::GetDepartment(size_t numOfDep)
{
	if (numOfDep > _items.size())
	{
		throw(exception("Ви передали більший номер відділу, ніж їх є у корпорації!"));
	}
	else
	{
		return &_items[numOfDep - 1];
	}
}

/*
Геттер для отримання кількості відділів корпорації
Вхід: відсутній
Вихід:
	GetNumberOfDepartments = _items.size() - кількість відділів
*/
int Firm::GetNumberOfDepartments()
{
	return _items.size();
}

/*
Геттер для відділів корпорації
Вхід: відсутній
Вихід:
	GetItems = items - відділи корпорації
*/
vector<Department> Firm::GetItems()
{
	vector<Department> items;
	for (auto item = _items.begin(); item != _items.end(); item++)
	{
		items.emplace_back(*item);
	}
	return items;
}

/*
Геттер для дати заснування корпорації
Вхід: відсутній
Вихід:
	GetCreationDate = creationDate - дата заснування корпорації
*/
string Firm::GetCreationDate()
{
	string day = "";
	if (_createdAt.GetDay() < 10)
	{
		day = "0";
		day += _createdAt.GetDay();
	}
	else
	{
		day = _createdAt.GetDay();
	}
	string creationDate;
	creationDate = _createdAt.GetYear();
	creationDate += ".";
	creationDate += _createdAt.GetMonth();
	creationDate += ".";
	creationDate += day;
	return creationDate;
}

/*
Геттер для назви корпорації
Вхід: відсутній
Вихід:
	GetName = _name - назва корпорації
*/
string Firm::GetName()
{
	return _name;
}

/*
Геттер для СЕО корпорації
Вхід: відсутній
Вихід:
	GetCEO = _chiefExecutiveOfficer - СЕО корпорації
*/
string Firm::GetCEO()
{
	return _chiefExecutiveOfficer;
}

/*
Геттер для прибутку корпорації
Вхід: відсутній
Вихід:
	GetProceeds = _proceeds - прибуток корпорації
*/
double Firm::GetProceeds()
{
	return _proceeds;
}

/*
Сеттер для всіх полів об'єкту класу
Вхід:
	items - відділи корпорації
	createdAt - дата заснування корпорації
	name - назва корпорації
	chiefExecutiveOfficer - СЕО корпорації
	proceeds - прибуток корпорації
Вихід: відсутній
*/
void Firm::Set(vector<Department> items, Date& createdAt, string name, string chiefExecutiveOfficer, double proceeds)
{
	SetItems(items);
	SetCreationDate(createdAt);
	SetName(name);
	SetCEO(chiefExecutiveOfficer);
	SetProceeds(proceeds);
}

/*
Сеттер для відділів корпорації
Вхід:
	items - посилання на відділи корпорації
Вихід: відсутній
*/
void Firm::SetItems(vector<Department> items)
{
	static_cast<void>(items.at(0));
	_items.clear();
	for (auto item = items.begin(); item != items.end(); item++)
	{
		_items.emplace_back(*item);
	}
}

/*
Сеттер для дати заснування корпорації
Вхід:
	createdAt - дата заснування корпорації
Вихід: відсутній
*/
void Firm::SetCreationDate(Date& createdAt)
{
	if (createdAt.GetYear() == "Невідомо" || createdAt.GetMonth() == "Невідомо" || createdAt.GetDay() == 0)
	{
		throw(exception("Ви не передали дати заснування!"));
	}
	_createdAt = createdAt;
}

/*
Сеттер для назви корпорації
Вхід:
	name - назва корпорації
Вихід: відсутній
*/
void Firm::SetName(string name)
{
	_name = name;
}

/*
Сеттер для СЕО корпорації
Вхід:
	chiefExecutiveOfficer - СЕО корпорації
Вихід: відсутній
*/
void Firm::SetCEO(string chiefExecutiveOfficer)
{
	_chiefExecutiveOfficer = chiefExecutiveOfficer;
}

/*
Сеттер для прибутку корпорації
Вхід:
	proceeds - прибуток корпорації
Вихід: відсутній
*/
void Firm::SetProceeds(double proceeds)
{
	_proceeds = proceeds;
}

/*
Метод для додавання нового відділу корпорації
Вхід:
	newDepartment - константна адреса нового відділу
Вихід: відсутній
*/
void Firm::Insert(const Department* newDepartment)
{
	if (newDepartment == NULL)
	{
		throw(exception("Ви не передали новий відділ!"));
	}
	_items.push_back(*newDepartment);
}

/*
Функція виводу до консолі інформації про корпорацію
Вхід: відсутній
Вихід: відсутній
*/
void Firm::Show()
{
	if (_createdAt.GetDay() < 10)
	{
		cout << "Дата створення корпорації: 0" << _createdAt.GetDay() << "." << _createdAt.GetMonth() << "." << _createdAt.GetYear() << endl;
	}
	else
	{
		cout << "Дата створення корпорації: " << _createdAt.GetDay() << "." << _createdAt.GetMonth() << "." << _createdAt.GetYear() << endl;
	}
	cout << "Назва корпорації: " << _name << endl;
	cout << "CEO корпорації: " << _chiefExecutiveOfficer << endl;
	cout << "Відділи корпорації:" << endl;
	int counter = 1;
	for (auto item : _items)
	{
		cout << "\nВідділ №" << counter << ":" << endl;
		item.Show();
		counter++;
	}
}

/*
Деструктор класу
Вхід: відсутній
Вихід: відсутній
*/
Firm::~Firm()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу Enterprice - " << this << endl << endl;
#endif 
}