#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "windows.h"
#define DEBUG
#include "Set.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Set array1;
	char name[4] = { 'a', 's', 'd', '\0' };
	array1.SetPlural(name);
	array1.Print();

	Set array3(array1);
	array3.Print();

	Set array4;
	array4 = array1;

	array4.Print();

	Set array5;
	char arr1[5] = { 'a','b','c','d','e' };
	array5.SetPlural(arr1, 5);

	'q' + array5;
	array5.Print();

	Set array6;
	char arr2[3] = { 'a','e','k' };
	array6.SetPlural(arr2, 3);

	char arr4[5] = { 'a','e','k','a','e' };
	char arr5[8] = { 'a','e','k','a','e','y','x','z' };
	Set array8;
	array8.SetPlural(arr4, 5);
	std::cout << array8.GetCurrentSize() << std::endl;
	array8.Print();
	std::cout << std::endl;
	array8.SetPlural(arr5, 8);
	std::cout << array8.GetCurrentSize() << std::endl;
	array8.Print();



	Set array10;
	char arr6[4] = { 'a','e','e','a' };
	char arr7[4] = { 'a','e','x','y' };
	array10.SetPlural(arr6, 4);
	array10.Print();
	'a' + array10;
	{
		Set a10(arr7, 4);
		a10 = array10;
		a10.Print();
	}
	array10.Print();


	cout << "Перевірка на рівність " << endl;

	Set a1("asd");
	Set a2("asd");
	a1.Print();
	a2.Print();
	if (a1 == a2)
		cout << "Множини рівні!" << endl;
	else
		cout << "Множини не рівні" << endl;


}
