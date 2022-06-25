#include "Workers.h"

class MarketingSpecialist : public Worker //успадковуЇтьс€ в≥д класу Worker
{
public: //компоненти класу, до €ких наданий публ≥чний доступ
	MarketingSpecialist(); //конструктор без параметр≥в за замовчуванн€м
	MarketingSpecialist(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int tasksNum); //конструктор з параметрами
	void Show() override; //функц≥€ дл€ виводу ≥нформац≥њ до консол≥
	void Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int tasksNum); //сеттер дл€ вс≥х пол≥в
	void SetTasksNum(int tasksNum); //сеттер дл€ к≥лькост≥ задач за м≥с€ць
	int GetNum() override; //геттер дл€ к≥лькост≥ задач за м≥с€ць
	~MarketingSpecialist() override; //деструктор за замовчуванн€м
protected:
	int _tasksNum; //к≥льк≥сть задач за м≥с€ць
};

class BusinessAnalyst : public Worker //успадковуЇтьс€ в≥д класу Worker
{
public: //компоненти класу, до €ких наданий публ≥чний доступ
	BusinessAnalyst(); //конструктор без параметр≥в за замовчуванн€м
	BusinessAnalyst(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int solvingProblems); //конструктор з параметрами
	void Show() override; //вив≥д даних про б≥знес-анал≥тика до консол≥
	void Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, int solvingProblems); //сеттер дл€ вс≥х пол≥в
	void SetSolvingProblems(int solvingProblems); //сеттер дл€ к≥лькост≥ вир≥шенн€ проблем за м≥с€ць
	int GetNum() override; //геттер дл€ к≥лькост≥ вир≥шенн€ проблем за м≥с€ць
	~BusinessAnalyst() override; //деструктор
protected:
	int _solvingProblems; //к≥льк≥сть вир≥шених проблем за м≥с€ць
};

class AdministrativeAssistant : public Worker //успадковуЇтьс€ в≥д класу Worker
{
public: //компоненти класу, до €ких наданий публ≥чний доступ
	AdministrativeAssistant(); //конструктор без параметр≥в за замовчуванн€м
	AdministrativeAssistant(string name, string profession, int age, int workExperience, double payment, bool workingPlace, bool administratorApproval); //конструктор з параметрами
	void Show() override; //вив≥д даних про пом≥чника адм≥н≥стратора до консол≥
	void Set(string name, string profession, int age, int workExperience, double payment, bool workingPlace, bool administratorApproval); //сеттер дл€ вс≥х пол≥в
	void SetAdministratorApproval(bool administratorApproval); //сеттер дл€ одобренн€ адм≥н≥стратора
	int GetNum() override; //геттер дл€ одобренн€ адм≥н≥стратора
	~AdministrativeAssistant() override; //деструктор
protected:
	bool _administratorApproval; //одобренн€ адм≥н≥стратора
};