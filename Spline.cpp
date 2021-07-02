//Spline is a special function defined piecewise by polynomials.

#include "pch.h"
#include <iostream>
#include <cmath>

const int n = 11;
//исходные данные
double x[n] = { 0.18, 0.65, 0.80, 0.92, 1.2, 1.59, 1.77, 1.83, 2.07, 2.38, 2.43 };
double y[n] = { 1.197, 1.915, 2.225, 2.509, 3.320, 4.903, 5.870, 6.233, 7.924, 10.804, 11.359 };

//вектор коэффицентов
double b[n] = { 0 };
double c[n] = { 0 };
double d[n] = { 0 };

//на каждом из отрезков будем искать сплайн функцию в виде полинома третей степени
double s(double z);

int main()
{
	double t;
	double h[n];
	c[0] = c[10] = 0;
	//обозначение шага
	for (int i = 0; i < n; i++)
		h[i] = x[i] - x[i - 1];
	//определение коэффицентов с
	for (int i = 1; i < n-1 ; i++)
	{
		t = 6 * (((y[i + 1] - y[i]) / h[i + 1]) - ((y[i] - y[i - 1]) / h[i]));
		c[i] = (t - h[i]*c[i-1] - h[i+1]*c[i+1])/(2*(h[i]-h[i+1]));
	}
	//определение коэффицентов d
	for (int i = 0; i < n; i++)
		d[i] = (c[i]-c[i-1])/h[i];
	//определение коэффицентов b
	for (int i = 0; i < n; i++)
		b[i] = (h[i]*c[i]/2)- ((h[i] * h[i] * d[i]) / 6) + ((y[i] - y[i-1]) / h[i]);
	//вывод
	std::cout << std::endl << " Lx(0.75)=" << s(0.75) << " " << std::endl;
	std::cout << " Lx(2.14)=" << s(2.14) << " " << std::endl;

	return 0;
}
//сплайн функция
double s(double z) {
	int i=0;
	for (; i < n; i++)
	{
		if (x[i - 1] <= z && z <= x[i])
			break;
	}
	return y[i] + (b[i] * (z - x[i])) + (c[i] / 2 * (z - x[i])*(z - x[i])) + (d[i] / 6 * (z - x[i])*(z - x[i])*(z - x[i]));
}