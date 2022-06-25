#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Worker
{
public: //компоненти класу, до яких наданий публічний доступ  
	Worker(); //конструктор без параметрів
	Worker(string name, string profession, int age, int work_experience, double payment, bool workingPlace); //конструктор з параметрами
	Worker(const Worker& other); //конструктор копіювання
	Worker(Worker&&) noexcept = default;
	Worker& operator=(Worker&&) = default;
	Worker& operator=(const Worker&) = default; //копіювання за допомогою оператора присвоювання за замовчуванням
	string GetName(); //геттер для імені без зазначеної кількості елементів для запису
	string GetProfession(); //геттер для професії
	int GetAge(); //геттер для віку
	int GetExperience(); //геттер для стажу роботи
	double GetPayment(); //геттер для зарплатні
	bool GetWorkingPlace(); //геттер для місця роботи
	virtual int GetNum();
	void Set(string name, string profession, int age, int work_experience, double payment, bool workingPlace); //сеттер для всіх полів
	void SetName(string name); //геттер для імені
	void SetProfession(string profession); //сеттер для професії
	void SetAge(int age); //геттер для віку
	void SetExperience(int work_experience); //сеттер для стажу роботи
	void SetPayment(double payment); //сеттер для зарплатні
	void SetWorkingPlace(bool workingPlace); //сеттер для місця роботи
	virtual void Show();
	Worker ComparePayment(const Worker& worker);
	virtual ~Worker(); //деструктор за замовчуванням
protected: //компоненти класу, до яких захищений доступ
	string _name; //ім'я робітника
	string _profession; //професія
	int _age; //вік робітника
	int _workExperience; //стаж роботи робітника
	double _payment; //зарплатня
	bool _workingPlace; //місце роботи(вдома чи в офісі)
};