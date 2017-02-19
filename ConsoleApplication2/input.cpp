#include <iostream>
#include <windows.h>
#include <exception>
using namespace std;

void input(void** firstArrayOfParameters, void** secondArrayOfParameters, int firstDegree, int secondDegree)
{
	double argument = 0;
	double tmp = 0;
	int size1 = firstDegree + 5;
	int size2 = secondDegree + 5;
	firstArrayOfParameters[0] = new int(size1);
	secondArrayOfParameters[0] = new int(size2);
	firstArrayOfParameters[1] = new int(firstDegree);
	secondArrayOfParameters[1] = new int(secondDegree);

	cout << "Введите значение аргумента:\n";
	cin >> argument;

	firstArrayOfParameters[2] = new double(argument);
	secondArrayOfParameters[2] = new double(argument);

	cout << "Введите коэффициенты полинома-числителя:\n";

	for (int i = 3; i < size1 - 1; i++)
	{
		cin >> tmp;
		firstArrayOfParameters[i] = new double(tmp);
	}

	cout << "Введите коэффициенты полинома-знаменателя:\n";

	for (int i = 3; i < size2 - 1; i++)
	{
		cin >> tmp;
		secondArrayOfParameters[i] = new double(tmp);
	}
}