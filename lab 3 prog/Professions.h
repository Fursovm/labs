#include "Workers.h"

class MarketingSpecialist : public Worker //успадковується від класу Employee
{
public: //компоненти класу, до яких наданий публічний доступ
	MarketingSpecialist() = default; //конструктор без параметрів за замовчуванням
	void Show() override; //функція для виводу інформації до консолі
	~MarketingSpecialist() override; //деструктор за замовчуванням
};

class BusinessAnalyst : public Worker //успадковується від класу Employee
{
public: //компоненти класу, до яких наданий публічний доступ
	BusinessAnalyst() = default; //конструктор без параметрів за замовчуванням
	void Show() override; //вивід даних про бізнес-аналітика до консолі
	~BusinessAnalyst() override; //деструктор
};

class AdministrativeAssistant : public Worker //успадковується від класу Employee
{
public: //компоненти класу, до яких наданий публічний доступ
	AdministrativeAssistant() = default; //конструктор без параметрів за замовчуванням
	void Show() override; //вивід даних про помічника адміністратора до консолі
	~AdministrativeAssistant() override; //деструктор
};