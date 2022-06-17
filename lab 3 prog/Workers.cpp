#define _CRT_SECURE_NO_WARNINGS
#include "string.h" 
#include <iostream>
#include "Workers.h"
//#define DEBUG 
using namespace std;

/*
Конструктор без параметрів
Вхід: відсутній
Вихід: відсутній
*/
Worker::Worker()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif та після нього 
    cout << "Викликався конструктор без параметрів класу Employee - " << this << endl << endl;
#endif 
    _name = "Невідомо";
    _workExperience = 0;
    _age = 0;
    _payment = 0;
    _workingPlace = 0;
}

/*
Конструктор з параметрами
Вхід:
  name - ім'я робітника
  age - вік робітника
  work_experience - стаж робітника
  payment - зарплатня робітника
  workingPlace - місце роботи робітника
Вихід: відсутній
*/
Worker::Worker(string name, string profession, int age, int workExperience, double payment, bool workingPlace)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до рядку #endif та після нього
    cout << "Викликався конструктор з параметрами класу Employee - " << this << endl << endl;
#endif
    Set(name, profession, age, workExperience, payment, workingPlace);
}

/*
Конструктор копіювання
Вхід:
  other - константне посилання на об'єкт класу Employee
Вихід: відсутній
*/
Worker::Worker(const Worker& other)
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до #endif і далі 
    cout << "Викликався конструктор копіювання класу Employee - " << this << endl << endl;
#endif 
    Set(other._name, other._profession, other._age, other._workExperience, other._payment, other._workingPlace);
}

/*
Геттер для імені робітника
Вхід: відсутній
Вихід:
  GetName = newName - ім'я робітника
*/
string Worker::GetName()
{
    return _name;
}

/*
Геттер для професії
Вхід: відсутній
Вихід:
    GetProfession = newProfession - професія робітника
*/
string Worker::GetProfession()
{
    return _profession;
}

/*
Геттер для віку робітника
Вхід: відсутній
Вихід:
  GetAge = _age - вік робітника
*/
int Worker::GetAge()
{
    return _age;
}

/*
Геттер для стажу робітника
Вхід: відсутній
Вихід:
  GetExperience = _workExperience - стаж робітника
*/
int Worker::GetExperience()
{
    return _workExperience;
}

/*
Геттер для зарплатні робітника
Вхід: відсутній
Вихід:
  GetPayment = _payment - зарплатня робітника
*/
double Worker::GetPayment()
{
    return _payment;
}

/*
Геттер для місця роботи робітника
Вхід: відсутній
Вихід:
  GetWorkingPlace = _workingPlace - місце роботи робітника
*/
bool Worker::GetWorkingPlace()
{
    return _workingPlace;
}

/*
Сеттер для всіх полів об'єкту класу
Вхід:
  name - ім'я робітника
  age - вік робітника
  work_experience - стаж робітника
  payment - зарплатня робітника
  workingPlace - місце роботи робітника
Вихід: відсутній
*/
void Worker::Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace)
{
    SetName(name);
    SetProfession(profession);
    SetAge(age);
    SetExperience(workExperience);
    SetPayment(payment);
    SetWorkingPlace(workingPlace);
}

/*
Сеттер для імені робітника
Вхід:
  name - ім'я робітника
Вихід: відсутній
*/
void Worker::SetName(string name)
{
    _name = name;
}

/*
Сеттер для професії
Вхід:
    profession - професія для задання
Вихід: відсутній
*/
void Worker::SetProfession(string profession)
{
    _profession = profession;
}

/*
Сеттер для віку робітника
Вхід:
  age - вік робітника
Вихід: відсутній
*/
void Worker::SetAge(int age)
{
    if (age < 18 || age > 65)
        throw(exception("Ви передали некоректне значення віку робітника!"));
    else
        _age = age;
}

/*
Сеттер для стажу робітника
Вхід:
  work_experience - стаж робітника
Вихід: відсутній
*/
void Worker::SetExperience(int work_experience)
{
    if (work_experience < 0 || work_experience > 46)
        throw(exception("Ви передали некоректне значення стажу робітника!"));
    else
        _workExperience = work_experience;
}

/*
Сеттер для зарплатні робітника
Вхід:
  payment - зарплатня робітника
Вихід: відсутній
*/
void Worker::SetPayment(double payment)
{
    if (payment >= 0)
    {
        _payment = payment;
    }
    else
    {
        throw(exception("Ви задали некоректне значення зарплатні!"));
    }
}

/*
Сеттер для місця роботи робітника
Вхід:
  workingPlace - місце роботи робітника
Вихід: відсутній
*/
void Worker::SetWorkingPlace(bool workingPlace)
{
    _workingPlace = workingPlace;
}

/*
Деструктор класу
Вхід: відсутній
Вихід: відсутній
*/
Worker::~Worker()
{
#ifdef DEBUG //якщо ми ідентифікували DEBUG, то виконується все до та після #endif 
    cout << "Викликався деструктор класу Employee - " << this << endl << endl;
#endif 
}