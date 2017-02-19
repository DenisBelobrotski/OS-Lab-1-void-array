#include <iostream>
#include <windows.h>
#include <exception>
using namespace std;

DWORD WINAPI polynomThread(LPVOID);

void runThreads(void** firstArrayOfParameters, void** secondArrayOfParameters)
{
	HANDLE numPolynomThread;
	DWORD IDNumPolynom;
	HANDLE denPolynomThread;
	DWORD IDDenPolynom;

	numPolynomThread = CreateThread(NULL, 0, polynomThread, (void*)firstArrayOfParameters, 0, &IDNumPolynom);
	if (numPolynomThread == NULL)
		throw exception("Ошибка при создании потока");

	denPolynomThread = CreateThread(NULL, 0, polynomThread, (void*)secondArrayOfParameters, 0, &IDDenPolynom);
	if (denPolynomThread == NULL)
		throw exception("Ошибка при создании потока");

	HANDLE* handles = new HANDLE[2];

	handles[0] = numPolynomThread;
	handles[1] = denPolynomThread;

	WaitForMultipleObjects(2, handles, TRUE, INFINITE);

	CloseHandle(numPolynomThread);
	CloseHandle(denPolynomThread);

	delete[] handles;
}