#define _CRT_SECURE_NO_WARNINGS 
#include "conio.h" 
#include "locale.h" 
#include "string.h" 
#include "windows.h" 
#include <iostream>
#include <algorithm>
#include "Firm.h"

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    AdministrativeAssistant AA1_1, AA1_2, AA2_1, AA2_2;
    MarketingSpecialist MS1_1, MS1_2, MS2_1, MS2_2;
    BusinessAnalyst BA1_1, BA1_2, BA2_1, BA2_2;

    AA1_1.Set("Анастасія", "Помічник адміністратора", 30, 10, 30000, true, true);
    AA1_2.Set("Єлизавета", "Помічник адміністратора", 40, 15, 32000, true, true);
    BA1_1.Set("Галина", "Бізнес-аналітик", 20, 2, 31000, false, 15);
    BA1_2.Set("Ніна", "Бізнес-аналітик", 36, 18, 48000, false, 22);
    MS1_1.Set("Сома", "Спеціаліст з маркетингу", 28, 10, 37000, true, 17);
    MS1_2.Set("Вероніка", "Спеціаліст з маркетингу", 25, 5, 34000, false, 12);

    AA2_1.Set("Георгій", "Помічник адміністратора", 40, 20, 50000, true, false);
    AA2_2.Set("Віталій", "Помічник адміністратора", 20, 1, 32000, true, true);
    BA2_1.Set("Олексій", "Бізнес-аналітик", 24, 3, 45000, false, 13);
    BA2_2.Set("Олександр", "Бізнес-аналітик", 38, 19, 65000, false, 9);
    MS2_1.Set("Сергій", "Спеціаліст з маркетингу", 19, 1, 20000, false, 19);
    MS2_2.Set("Святослав", "Спеціаліст з маркетингу", 26, 7, 34000, true, 20);

    vector<Worker*> vWorkers1;
    vWorkers1.emplace_back(&BA1_1);
    vWorkers1.emplace_back(&AA1_1);
    vWorkers1.emplace_back(&MS1_1);
    vWorkers1.emplace_back(&BA1_2);
    vWorkers1.emplace_back(&AA1_2);
    vWorkers1.emplace_back(&MS1_2);

    vector<Worker*> vWorkers2;
    vWorkers2.emplace_back(&MS2_2);
    vWorkers2.emplace_back(&AA2_2);
    vWorkers2.emplace_back(&BA2_1);
    vWorkers2.emplace_back(&MS2_1);
    vWorkers2.emplace_back(&AA2_1);
    vWorkers2.emplace_back(&BA2_2);

    Department dep1, dep2;
    vector<Department> items;
    dep1.Set(vWorkers1, "Маркетинг");
    dep2.Set(vWorkers2, "Фінанси");
    items.push_back(dep1);
    items.push_back(dep2);
    Date createdAt;
    createdAt.Set("2000", "10", 10);
    string name = "NVIDIA Corp.";
    string owner = "Джен-Хсун Хуанг";
    double proceeds = 7640000000;

    Firm firm(items, createdAt, name, owner, proceeds);
    firm.Set(items, createdAt, name, owner, proceeds);

    cout << "===Корпорація до додавання нового відділу та робітників:===" << endl;
    firm.Show();

    cout << "=============================================================" << endl;

    AA1_1.Show();
    AA1_2.Show();

    AA1_1.ComparePayment(AA1_2);

    Department dep3;
    AdministrativeAssistant AA3_1, AA3_2;
    MarketingSpecialist MS3_1, MS3_2;
    BusinessAnalyst BA3_1, BA3_2;

    AA3_1.Set("Тетяна", "Помічник адміністратора", 30, 10, 30000, true, true);
    AA3_2.Set("Ірина", "Помічник адміністратора", 40, 15, 32000, true, true);
    BA3_1.Set("Наталья", "Бізнес-аналітик", 20, 2, 31000, false, 7);
    BA3_2.Set("Джесіка", "Бізнес-аналітик", 36, 18, 48000, false, 27);
    MS3_1.Set("Ярослава", "Спеціаліст з маркетингу", 28, 10, 37000, true, 14);
    MS3_2.Set("Яворина", "Спеціаліст з маркетингу", 25, 5, 34000, false, 24);

    vector<Worker*> vWorkers3;
    vWorkers3.emplace_back(&BA3_1);
    vWorkers3.emplace_back(&AA3_1);
    vWorkers3.emplace_back(&MS3_1);
    vWorkers3.emplace_back(&AA3_2);
    vWorkers3.emplace_back(&BA3_2);
    vWorkers3.emplace_back(&MS3_2);
    /*  SortWorkers(vWorkers3);*/

    dep3.Set(vWorkers3, "Людські ресурси");
    firm.Insert(&dep3);

    BusinessAnalyst newBA;
    newBA.Set("Ігор", "Бізнес-аналітик", 26, 4, 44000, false, 17);
    AdministrativeAssistant newAA;
    newAA.Set("Хрістіна", "Помічник адміністратора", 23, 1, 21000, true, true);
    MarketingSpecialist newMS;
    newMS.Set("Майкл", "Спеціаліст з маркетингу", 47, 23, 67000, false, 15);
    firm.GetDepartment(1)->Insert(&newBA, "Бізнес-аналітик");
    firm.GetDepartment(1)->Insert(&newAA, "Помічник адміністратора");
    firm.GetDepartment(1)->Insert(&newMS, "Спеціаліст з маркетингу");

    cout << "\n===Корпорація після додавання нового відділу та робітників:===\n" << endl;
    firm.Show();

    AdministrativeAssistant AA4_1, AA4_2, AA4_3;

    AA4_1.Set("Вероніка", "Помічник адміністратора", 32, 9, 30000, true, true);
    AA4_2.Set("Григорій", "Помічник адміністратора", 25, 7, 32000, true, true);
    AA4_3.Set("Яворина", "Бізнес-аналітик", 24, 2, 31000, false, true);

    vector<AdministrativeAssistant*> vWorkers4;
    vWorkers4.emplace_back(&AA4_1);
    vWorkers4.emplace_back(&AA4_2);
    vWorkers4.emplace_back(&AA4_3);
    firm.GetDepartment(2)->SetWorkersByProf(vWorkers4);

    cout << "Імена службовців зі стажем не менше 10 років:" << endl;
    int numOfDep = firm.GetNumberOfDepartments();
    for (int i = 1; i <= numOfDep; i++)
    {
        auto vAA5 = firm.GetDepartment(i)->GetWorkersAA();
        vector<AdministrativeAssistant> correctAA;
        copy_if(vAA5.begin(), vAA5.end(), back_inserter(correctAA), [](const AdministrativeAssistant& AA)
            {
                return const_cast<AdministrativeAssistant*>(&AA)->GetExperience() >= 10;
            });
        for (auto AA : correctAA)
        {
            cout << AA.GetName() << endl;
        }

        auto vBA5 = firm.GetDepartment(i)->GetWorkersBA();
        vector<BusinessAnalyst> correctBA;
        copy_if(vBA5.begin(), vBA5.end(), back_inserter(correctBA), [](const BusinessAnalyst& BA)
            {
                return const_cast<BusinessAnalyst*>(&BA)->GetExperience() >= 10;
            });
        for (auto BA : correctBA)
        {
            cout << BA.GetName() << endl;
        }

        auto vMS5 = firm.GetDepartment(i)->GetWorkersMS();
        vector<MarketingSpecialist> correctMS;
        copy_if(vMS5.begin(), vMS5.end(), back_inserter(correctMS), [](const MarketingSpecialist& MS)
            {
                return const_cast<MarketingSpecialist*>(&MS)->GetExperience() >= 10;
            });
        for (auto MS : correctMS)
        {
            cout << MS.GetName() << endl;
        }
    }

    cout << endl << endl << "Імена всіх бізнес-аналітиків корпорації:" << endl;
    for (int i = 1; i <= numOfDep; i++)
    {
        auto vBA6 = firm.GetDepartment(i)->GetWorkersBA();
        for (auto BA : vBA6)
        {
            cout << BA.GetName() << endl;
        }
    }
    
 
    return 0;
}