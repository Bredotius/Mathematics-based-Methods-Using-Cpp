#include "pch.h"
#include <iostream>
using namespace std;
//исходная функция
double f(double x)
{
	return (2 * x*x*x - 7 * x + 4);
}

//Quadrature rule is an approximation of the definite integral of a function, usually stated as a weighted sum of function values at specified points within the domain of integration.
int main()
{
	setlocale(LC_ALL, "Rus");
	double a, b;//обьявление переменных для ввода пределов интегрированния
	const int n = 4;//число узлов
	//значения узлов для n = 4
	float x[n] = { 0.06943184, 0.33000948, 0.66999052, 0.93056816 };
	//значения коффициентов
	float A[n] = { 0.17392742, 0.32607258, 0.32607258, 0.17392742};
	cout << "Введите начало отрезка: ";
	cin >> a;
	cout << "Введите конец отрезка: ";
	cin >> b;
	double s = 0;
	double h = (b - a);//отрезок интегрирования
	for (int i = 0; i < n; i++)
	{
		//значение интеграла в узле
		s += A[i]*f(a + (b - a)*x[i]);
	}
	//приближенное значение интеграла
	double I = h * s;
	cout << "Результат интегрирования: " << I << endl;
	return 0;
}

//Chebyshev–Gauss quadrature is an extension of Gaussian quadrature method for approximating the value of integrals
int main()
{
	setlocale(LC_ALL, "Rus");
	double a, b;//обьявление переменных для ввода пределов интегрированния
	int n = 4;//число узлов
	//значения узлов для n = 4
	float x[4] = { 0.794654, 0.187592, -0.187592, -0.794654};
	cout << "Введите начало отрезка: ";
	cin >> a;
	cout << "Введите конец отрезка: ";
	cin >> b;
	double s = 0;
	double h = (b - a)/n;//шаг интегрирования
	for (int i = 0; i < n; i++)
	{
		//значение интеграла в узле
		s += f((a + b)/2 + ((b-a)/2)*x[i]);
	}
	//приближенное значение интеграла
	double I = h * s;
	cout << "Результат интегрирования: " << I << endl;
	return 0;
}