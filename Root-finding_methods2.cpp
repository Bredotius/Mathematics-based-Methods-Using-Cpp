//Newton's method  is a root-finding algorithm which produces successively better approximations to the roots (or zeroes) of a real-valued function.
//Secant method is a root-finding algorithm that uses a succession of roots of secant lines to better approximate a root of a function f. 
//Fixed-point iteration is a method of computing fixed points of a function.

#include "pch.h"
#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

float f(float x)
{
	return 2* pow(x, 2) - 5 - pow(2, x);
}

float fi(float x)
{
	return 4 * x - pow(2, x) * log(2);
}

float fii(float x)
{
	return 4 - pow(2, x) * pow(log(2), 2);
}

float q(float x)
{
	return sqrt((pow(2, x)+5)/2);
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "RUSSIAN");
	float c, x = 0, x0, E = 0.0001;
	int i=0;
	
	//Newton's method
	cout << "\n Метод Ньютона:\n";
	x = 3;
	while (abs(f(x)) > E)
	{
		x = x - f(x) / fi(x);
		i++;
	}

	//Secant method
	cout << "\n Метод секущих:\n";
	x = 3;
	x0 = 3.5;
	while (abs(f(x)) > E)
	{
		c = x;
		x = x - f(x)*(x-x0)/(f(x)-f(x0));
		x0 = c;
		i++;
	}

	//Fixed-point iteration
	cout << "\n Метод простых итераций:\n";
	x = 0.7;
	while (abs(f(x)) > E)
	{
		x = q(x);
		i++;
	}
	cout << " Корень уравнения = " << x;
	cout << "\n Число итераций = " << i;
	cout << endl << " Время = " << clock() / 1000.0 << "\n\n"; // время работы программы
	
	system("pause");
	return 0;
}