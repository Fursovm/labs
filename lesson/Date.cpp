#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Date.h"

	void Date::Print()
	{
		printf("%02d.%02d.%2d", _day, _month, _year);
	}

	int Date::IsleapYear(int day, int month, int year)
	{
		if (year % 4 || (year % 100 == 0 && year % 400))
			return 0;
		else
			return 1;
	}

    int Date::CheckDate(int day, int month, int year)
    {
        if (year < 0)
        {
            return 0;
        }

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (day < 1 || day > 31)
            {
                return 0;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11 || month == 8 || month == 11)
        {
            if (day < 1 || day > 30)
            {
                return 0;
            }
        }
        else if (month == 2)
        {
            if (IsleapYear(day, month, year) == 0)
            {
                if (day < 1 || day > 28)
                {
                    return 0;
                }
            }
            else
            {
                if (day < 1 || day > 29)
                {
                    return 0;
                }
            }
        }
        else
        {
            return 0;
        }

        return 1;
    }

    void Date::InputDate()
    {
        int day;
        int month;
        int year;

        do
        {
            printf("Day - ");
            scanf("%d", &day);
            printf("Month - ");
            scanf("%d", &month);
            printf("Year - ");
            scanf("%d", &year);
        } while (CheckDate(day, month, year) == 0);

        _day = day;
        _month = month;
        _year = year;
    }

    int Date::SetDate(int day, int month, int year)
    {
        if (CheckDate(day, month, year) == 0)
            return 0;
        else
        {
            _day = day;
            _month = month;
            _year = year;
            return 1;
        }
    }
    