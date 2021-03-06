//For a given set of points (x[j],y[j]) with no two x[j] values equal, the Lagrange polynomial is the polynomial of lowest degree that assumes at each value x[j] the corresponding value y[j], so that the functions coincide at each point.
//Newton polynomial, named after its inventor Isaac Newton, is an interpolation polynomial for a given set of data points.

#include "pch.h"
#include <iostream>
#include <math.h>
#include <ctime>

const int n = 11;
double x[n] = { 0.18, 0.65, 0.80, 0.92, 1.2, 1.59, 1.77, 1.83, 2.07, 2.38, 2.43 };
double y[n] = { 1.197, 1.915, 2.225, 2.509, 3.320, 4.903, 5.870, 6.233, 7.924, 10.804, 11.359 };

double lagranzx(double t);
double lagranzy(double t);
double newton(double t);
double newtony(double t);

int main()
{
    std::cout << " Hello World!\n"; 
	std::cout << " Lx(0.75)=" << lagranzx(0.75) << " " << std::endl;
	std::cout << " Lx(2.14)=" << lagranzx(2.14) << " " << std::endl;
	std::cout << " Ly(2.087)=" << lagranzy(2.087) << " " << std::endl;
	std::cout << " Ly(9.769)=" << lagranzy(9.769) << " " << std::endl;
	std::cout << " Nx(0.75)=" << newton(0.75) << " " << std::endl;
	std::cout << " Nx(2.14)=" << newton(2.14) << " " << std::endl;
	std::cout << " Ny(2.087)=" << newtony(2.087) << " " << std::endl;
	std::cout << " Ny(9.769)=" << newtony(9.769) << " " << std::endl;
	std::cout << std::endl << " Время = " << clock() / 1000.0 << "\n\n";
	system("pause");
	return 0;
}

double lagranzx(double t) {
	double z, p1, p2;
	z = 0;
	//реализация формулы Лагранжа для поиска приближенного значения f(x) в точке t
	for (int j = 0; j < n; j++) {
		p1 = 1; p2 = 1;
		for (int i = 0; i < n; i++) {
			if (i == j) {
				p1 = p1 * 1; p2 = p2 * 1;
			}
			else {
				p1 = p1 * (t - x[i]);
				p2 = p2 * (x[j] - x[i]);
			}
		}
		z = z + y[j] * p1 / p2;
	}
	return z;
}

double lagranzy(double t) {
	double z, p1, p2;
	z = 0;
	//реализация формулы Лагранжа для поиска приближенного значения t в точке y
	for (int j = 0; j < n; j++) {
		p1 = 1; p2 = 1;
		for (int i = 0; i < n; i++) {
			if (i == j) {
				p1 = p1 * 1; p2 = p2 * 1;
			}
			else {
				p1 = p1 * (t - y[i]);
				p2 = p2 * (y[j] - y[i]);
			}
		}
		z = z + x[j] * p1 / p2;
	}
	return z;
}

double newton(double t) {
	double k[n];
	//создание массива коэффициентов
	k[0] = y[0];
	for (int j = 1; j < n; j++)
		for (int i = 0; i < n - j; i++)
		{
			y[i] = (y[i + 1] - y[i]) / (x[i + j] - x[i]);
			k[j] = y[0];
		}
	//реализация формулы Ньютона для поиска приближенного значения t в точке y
	double S = k[0], p = 1;
	for (int i = 1; i < n; i++)
	{
		p = p * (t - x[i - 1]);
		S += k[i] * p;
	}
	return S;
}

double newtony(double t) {
	double k[n];
	//создание массива коэффициентов
	k[0] = x[0];
	for (int j = 1; j < n; j++)
		for (int i = 0; i < n - j; i++)
		{
			x[i] = (x[i + 1] - x[i]) / (y[i + j] - y[i]);
			k[j] = x[0];
		}
	//реализация формулы Ньютона для поиска приближенного значения t в точке y
	double S = k[0], p = 1;
	for (int i = 1; i < n; i++)
	{
		p = p * (t - y[i - 1]);
		S += k[i] * p;
	}
	return S;
}