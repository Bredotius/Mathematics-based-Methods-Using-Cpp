
#include "pch.h"
#include <iostream>
#include "math.h"
#include <ctime>
using namespace std;

float f(float x)
{
	return sqrt(4*x+7)-3*cos(x);
}

float fi(float x)
{
	return 3*sin(x) + 2/sqrt(4 * x + 7);
}

float fii(float x)
{
	return 3 * cos(x) - 4/pow((4 * x + 7),(3/2));
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "RUSSIAN");
	float a = -1.5, b = 0, x, E=0.001;
	int i=0;
    std::cout << "Hello World!\n"; 
	//Метод хорд и касательных
	cout << "\n Метод хорд и касательных:\n";
	while (abs(a - b) > E)
	{
		if (f(a)*fii(a) < 0)
			a = a - f(a)*(a - b) / (f(a) - f(b));
		else if (f(a)*fii(a) > 0)
			a = a - f(a)/fi(a);
		if (f(b)*fii(b) < 0)
			b = b - f(b)*(b - a) / (f(b) - f(a));
		else if (f(b)*fii(b) > 0)
			b = b - f(b) / fi(b);
		i++;
	}
	x = (a + b) / 2;
	//Метод золотого сечения и касательных
	cout << "\n Метод золотого сечения и касательных:\n";
	float a = -0.5, b = 1, x, x1, x2, z=1.618, E = 0.00001;
	int i = 0;
	while (abs(a - b) > E)
	{
		x1 = b - (b - a) / z;
		x2 = a + (b - a) / z;
		if (f(a)*fii(a) < 0)
			a = x1;
		else if (f(a)*fii(a) > 0)
			a = a - f(a) / fi(a);
		if (f(b)*fii(b) < 0)
			b = x2;
		else if (f(b)*fii(b) > 0)
			b = b - f(b) / fi(b);
		i++;
	}
	x = (a + b) / 2;
	cout << " Корень уравнения = " << x;
	cout << "\n Число итераций = " << i;
	cout << endl << " Время = " << clock() / 1000.0 << "\n\n"; // время работы программы
}