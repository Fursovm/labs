#pragma once
#include "Professions.h"

class Department
{
public: //компоненти класу, до яких наданий публічний доступ
	Department(); //конструктор без параметрів
	Department(vector<Worker*> workers, string name); //конструктор з параметрами
	Department(const Department& other); //конструктор копіювання
	string GetName(); //геттер для назви відділу без зазначеної кількості елементів для запису
	vector<Worker*> GetWorkers(); //геттер для всіх робітників відділу
	vector<AdministrativeAssistant> GetWorkersAA();  //геттер для помічників адміністратора
	vector<BusinessAnalyst> GetWorkersBA(); //геттер для бізнес-аналітиків
	vector<MarketingSpecialist> GetWorkersMS(); //геттер для спеціалістів з маркетингу
	void Set(vector<Worker*> workers, string name); //сеттер для всіх полів
	void SetWorkers(vector<Worker*> workers); //сеттер для всіх робітників відділу
	template <typename T>
	void SetWorkersByProf(vector<T>& workers);
	void SetName(string name); //сеттер для назви
	void Insert(Worker* newWorker, string profession); //додати нового робітника у відділ
	void Show(); //вивід даних про відділ до консолі
	~Department(); //деструктор
protected: //компоненти класу, до яких захищений доступ
	vector<Worker*> _workers; //робітники відділу
	string _name; //назва

	template <typename T>
	vector<T> GetWorkersByProf(vector<T>& vector, string profession); //геттер для робітників за їхньою професією
};