#define _CRT_SECURE_NO_WARNINGS 
#include "Professions.h"
using namespace std;

MarketingSpecialist::MarketingSpecialist()
{
	_profession = "Спеціаліст по маркетингу";
	_name = "Невідомо";
	_workExperience = 0;
	_age = 0;
	_payment = 0;
	_workingPlace = 0;
	_tasksNum = 0;
}

MarketingSpecialist::MarketingSpecialist(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int tasksNum)
{
	Set(name, profession, age, workExperience, payment, workingPlace, tasksNum);
}

BusinessAnalyst::BusinessAnalyst()
{
	_profession = "Бізнес Аналітик";
	_name = "Невідомо";
	_workExperience = 0;
	_age = 0;
	_payment = 0;
	_workingPlace = 0;
	_solvingProblems = 0;
}

BusinessAnalyst::BusinessAnalyst(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int solvingProblems)
{
	Set(name, profession, age, workExperience, payment, workingPlace, solvingProblems);
}

AdministrativeAssistant::AdministrativeAssistant()
{
	_profession = "Бізнес Адміністратор";
	_name = "Невідомо";
	_workExperience = 0;
	_age = 0;
	_payment = 0;
	_workingPlace = 0;
	_administratorApproval = false;
}

AdministrativeAssistant::AdministrativeAssistant(string name, string profession, int age, int workExperience, double payment, bool workingPlace, bool administratorApproval)
{
	Set(name, profession, age, workExperience, payment, workingPlace, administratorApproval);
}

/*
Функція виводу до консолі інформації про спеціаліста з маркетингу
Вхід: відсутній
Вихід: відсутній
*/
void MarketingSpecialist::Show()
{
	cout << "\nІм'я: " << _name << endl;
	cout << "Вік: " << _age << endl;
	cout << "Робочий стаж: " << _workExperience << endl;
	cout << "Посада: спеціаліст з маркетингу" << endl;
	cout << "Кількість задач за місяць " << _tasksNum << endl;
	cout << "Зарплатня: " << _payment << " грн/місяць" << endl;
	if (_workingPlace == true)
	{
		cout << "Місце роботи: в офісі" << endl;
	}
	else
	{
		cout << "Місце роботи: вдома" << endl;
	}
}

/*
Функція виводу до консолі інформації про бізнес-аналітика
Вхід: відсутній
Вихід: відсутній
*/
void BusinessAnalyst::Show()
{
	cout << "\nІм'я: " << _name << endl;
	cout << "Вік: " << _age << endl;
	cout << "Робочий стаж: " << _workExperience << endl;
	cout << "Посада: бізнес-аналітик" << endl;
	cout << "Вирішених проблем за місяць " << _solvingProblems << endl;
	cout << "Зарплатня: " << _payment << " грн/місяць" << endl;
	if (_workingPlace == true)
	{
		cout << "Місце роботи: в офісі" << endl;
	}
	else
	{
		cout << "Місце роботи: вдома" << endl;
	}
}

/*
Функція виводу до консолі інформації про помічника адміністратора
Вхід: відсутній
Вихід: відсутній
*/
void AdministrativeAssistant::Show()
{
	cout << "\nІм'я: " << _name << endl;
	cout << "Вік: " << _age << endl;
	cout << "Робочий стаж: " << _workExperience << endl;
	cout << "Посада: помічник адміністратора" << endl;
	cout << "Зарплатня: " << _payment << " грн/місяць" << endl;
	if (_administratorApproval)
		cout << "Одобрення адміністратора є" << endl;
	else
		cout << "Одобрення адміністратора немає" << endl;

	if (_workingPlace == true)
	{
		cout << "Місце роботи: в офісі" << endl;
	}
	else
	{
		cout << "Місце роботи: вдома" << endl;
	}
}

void MarketingSpecialist::Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int tasksNum)
{
	SetName(name);
	SetProfession(profession);
	SetAge(age);
	SetExperience(workExperience);
	SetPayment(payment);
	SetWorkingPlace(workingPlace);
	SetTasksNum(tasksNum);
}

void BusinessAnalyst::Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int solvingProblems)
{
	SetName(name);
	SetProfession(profession);
	SetAge(age);
	SetExperience(workExperience);
	SetPayment(payment);
	SetWorkingPlace(workingPlace);
	SetSolvingProblems(solvingProblems);
}

void AdministrativeAssistant::Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, bool administratorApproval)
{
	SetName(name);
	SetProfession(profession);
	SetAge(age);
	SetExperience(workExperience);
	SetPayment(payment);
	SetWorkingPlace(workingPlace);
	SetAdministratorApproval(administratorApproval);
}

void MarketingSpecialist::SetTasksNum(int tasksNum)
{
	if (tasksNum < 0)
		throw(exception("Ви передали некоректне значення задач робітника!"));
	else _tasksNum = tasksNum;
}

void BusinessAnalyst::SetSolvingProblems(int solvingProblems)
{
	if (solvingProblems < 0)
		throw(exception("Ви передали некоректне значення вирішених проблем робітника!"));
	else _solvingProblems = solvingProblems;
}

void AdministrativeAssistant::SetAdministratorApproval(bool administratorApproval)
{
	if (administratorApproval > 1 || administratorApproval < 0)
		throw(exception("Ви передали некоректне значення одобрення адміністратора!"));
	else _administratorApproval = administratorApproval;
}

int MarketingSpecialist::GetNum()
{
	return _tasksNum;
}

int BusinessAnalyst::GetNum()
{
	return _solvingProblems;
}

int AdministrativeAssistant::GetNum()
{
	return _administratorApproval;
}


/*
Деструктор класу
Вхід: відсутній
Вихід: відсутній
*/
BusinessAnalyst::~BusinessAnalyst()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу BusinessAnalyst - " << this << endl << endl;
#endif 
}

/*
Деструктор класу
Вхід: відсутній
Вихід: відсутній
*/
MarketingSpecialist::~MarketingSpecialist()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу MarketingSpecialist - " << this << endl << endl;
#endif 
}

/*
Деструктор класу
Вхід: відсутній
Вихід: відсутній
*/
AdministrativeAssistant::~AdministrativeAssistant()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
	cout << "Викликався деструктор класу AdministrativeAssistant - " << this << endl << endl;
#endif 
}
