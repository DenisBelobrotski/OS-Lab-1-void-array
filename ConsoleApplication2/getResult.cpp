#include <iostream>
#include <windows.h>
#include <exception>
using namespace std;

double getResult(void** firstArrayOfParameters, void** secondArrayOfParameters)
{
	int size1 = *(int*)firstArrayOfParameters[0];
	int size2 = *(int*)secondArrayOfParameters[0];
	double numerator = *(double*)firstArrayOfParameters[size1 - 1];
	double denominator = *(double*)secondArrayOfParameters[size2 - 1];

	if (denominator == 0) 
		throw exception("Значение полинома-знаменателя равно 0!");
	else
		return (numerator / denominator);
}