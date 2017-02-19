#include <iostream>
#include <windows.h>
#include <exception>
using namespace std;

void input(void**, void**, int, int);
void runThreads(void**, void**);
double getResult(void**, void**);
void outputResult(double, double);

int main()
{
	setlocale(LC_ALL, "rus");

	int firstDegree = 0;
	int secondDegree = 0;
	
	cout << "Введите степень полинома-числителя (целое неотрицательное число):\n";
	cin >> firstDegree;
	cout << "Введите степень полинома-знаменателя (целое неотрицательное число):\n";
	cin >> secondDegree;

	void** firstArrayOfParameters = new void*[firstDegree + 5];
	void** secondArrayOfParameters = new void*[secondDegree + 5];
	
	try
	{
		if (firstDegree < 0 || secondDegree < 0)
			throw exception("Неверная степень полинома!");
		else
		{
			input(firstArrayOfParameters, secondArrayOfParameters, firstDegree, secondDegree);
			runThreads(firstArrayOfParameters, secondArrayOfParameters);
			outputResult(getResult(firstArrayOfParameters, secondArrayOfParameters), *(double*)firstArrayOfParameters[2]);

			for (int i = 0; i < firstDegree + 5; i++)
				delete [] firstArrayOfParameters[i];
			delete [] firstArrayOfParameters;

			for (int i = 0; i < secondDegree + 5; i++)
				delete [] secondArrayOfParameters[i];
			delete [] secondArrayOfParameters;
		}
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	return 0;
}