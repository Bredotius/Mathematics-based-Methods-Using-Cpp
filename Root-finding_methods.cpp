//Golden-section searchis a technique for finding an extremum (minimum or maximum) of a function inside a specified interval.
//Bisection method is a root-finding method that applies to any continuous functions for which one knows two values with opposite signs.
//Secant method is a root-finding algorithm that uses a succession of roots of secant lines to better approximate a root of a function f.

#include "pch.h"
#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

float f(float x)
{
	return x * sin(x) - 1;
}

float fi(float x)
{
	return sin(x) + x * cos(x);
}

float fii(float x)
{
	return 2 * cos(x) - x * sin(x);
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "RUSSIAN");
	float a = 0, b = 2, c = 0, E = 0.001, x=0, i = 0, y,x1,x2,z=1.618;
	//Golden-section search
	cout << "\n Метод золотого сечения:\n";
	while (abs(b-a)>=E)
	{
		x1 = b - (b - a) / z;
		x2 = a + (b - a) / z;
		if ((f(a) <= 0 && f(x1) >= 0) || (f(a) >= 0 && f(x1) <= 0))
			b = x1;
		else if ((f(x2) <= 0 && f(b) >= 0) || (f(x2) >= 0 && f(b) <= 0)) 
			a = x2;
		else {
			a = x1;
			b = x2;
		}
		i++;
	}
	x = (a + b) / 2;
	cout << " Корень уравнения на интервале [0;2] = " << x;
	cout << "\n Число итераций = " << i;
	cout << endl << " Время = " << clock() / 1000.0 << "\n\n"; // время работы программы
	/*
	//Bisection method
	cout << "\n Метод половинного деления:\n";
	while (abs(b-a) > 2 * E)
	{
		c = (a + b) / 2;
		if ((f(a) <= 0 && f(c) >= 0) || (f(a) >= 0 && f(c) <= 0))
			b = c;
		else if ((f(c) <= 0 && f(b) >= 0) || (f(c) >= 0 && f(b) <= 0))
			a = c;
		i++;
	}
	x = (a + b) / 2;
	cout << " Корень уравнения на интервале [0;2] = "<< x;
	cout << "\n Число итераций = "<< i;
	cout << endl << " Время = " << clock() / 1000.0 << "\n\n"; // время работы программы
	
	//Secant method
	cout << "\n Метод хорд:\n";
	if (f(a) >= 0 && f(b) <= 0)
	{
		x = b;
		c = a;
		y = a;
	}
	else if (f(b) >= 0 && f(a) <= 0)
	{ 
		x = a;
		c = b;
		y = b;
	}
	while (abs(x-c) > E)
	{
		c = x;
		x = c - (y - c)*f(c)/(f(y) - f(c));
		i++;
	}
	cout << " Корень уравнения на интервале [0;2] = " << x;
	cout << "\n Число итераций = " << i;
	cout << endl << " Время = " << clock() / 1000.0 << "\n\n"; // время работы программы
	
	//Метод Ньютона (касательных)
	cout << "\n Метод Ньютона:\n";
	while (f(x)*fii(x) < 0)
		x += 0.1;
	while (abs(f(x)) > E)
	{
		x = x - f(x) / fi(x);
		i++;
	}
	cout << " Корень уравнения = " << x;
	cout << "\n Число итераций = " << i;
	cout << endl << " Время = " << clock() / 1000.0 << "\n\n"; // время работы программы

	//Метод секущих
	float a = 0, b = 2, c = 0, E = 0.001, x = 1.7, i = 0, y, x0 = 2;
	cout << "\n Метод секущих:\n";
	while (abs(f(x)) > E)
	{
		c = x;
		x = x - f(x)*(x-x0)/(f(x)-f(x0));
		x0 = c;
		i++;
	}
	cout << " Корень уравнения = " << x;
	cout << "\n Число итераций = " << i;
	cout << endl << " Время = " << clock() / 1000.0 << "\n\n"; // время работы программы */

	system("pause");
	return 0;
}