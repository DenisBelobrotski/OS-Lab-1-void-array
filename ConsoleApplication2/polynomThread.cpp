#include <iostream>
#include <windows.h>
#include <exception>
using namespace std;

DWORD WINAPI polynomThread(LPVOID parameter)
{
	void** arrayOfParameters = (void**)parameter;
	int size = *(int*)arrayOfParameters[0];
	int degree = *(int*)arrayOfParameters[1];
	double argument = *(double*)arrayOfParameters[2];
	double result = 0;

	cout << "Степень полинома:\n" << degree << endl;
	cout << "Коэффициенты полинома:\n";

	for (int i = 3; i < size - 1; i++)
	{
		cout << *(double*)arrayOfParameters[i] << " ";
		result += *(double*)arrayOfParameters[i] * pow(argument, degree);
		degree--;
		Sleep(17);
	}

	cout << endl << "p(" << argument << ") = " << result << endl;

	arrayOfParameters[size - 1] = new double(result);

	return 0;
}