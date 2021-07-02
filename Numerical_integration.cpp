//Riemann sum is a certain kind of approximation of an integral by a finite sum.
#include "pch.h"
#include <iostream>
using namespace std;

double f(double x)
{
	return (2 * x*x*x - 7 * x + 4);
}
int main()
{
	setlocale(LC_ALL, "Rus");
	double a, b;
	int n;
	cout << "Введите начало отрезка: ";
	cin >> a;
	cout << "Введите конец отрезка: ";
	cin >> b;
	cout << "Введите количество отрезков разбиения: ";
	cin >> n;
	double s = (f(a) + f(b)) / 2;
	double h = (b - a) / n;
	for (int i = 1; i <= n - 1; i++)
	{
		s += f(a + i * h);
	}
	double I = h * s;
	cout << "Результат интегрирования: " << I << endl;

	return 0;
}

//Trapezoidal rule is a technique for approximating the definite integral.
#include <iostream>
#include <math.h>
using namespace std;
double f(double x) { return (-3 * x*x + 2 * x + 9); }
double In(double a, double b, int n, double y) { return ((b - a) / (2 * n)*y); }
int main() {
	setlocale(LC_ALL, "Rus");
	int n; double a, b, y=0, dy, I;
	cout << "Введите начало отрезка: ";
	cin >> a;
	cout << "Введите конец отрезка: ";
	cin >> b;
	cout << "Введите количество отрезков разбиения: ";
	cin >> n;
	dy = (b - a) / n;
	y += f(a) + f(b);
	for (int i = 1; i < n; i++) { y += 2 * (f(a + dy * i)); }
	I = In(a, b, n, y);
	cout << "Результат интегрирования: " << I << endl;
	return 0;
}

//Simpson's rules are several approximations for definite integrals.
#include <iostream>
#include <math.h>
using namespace std;

double f(double x)
{
	return sin(x*x + 2 * x);
}

int main() {
	setlocale(LC_ALL, "Rus");
	double a, b, eps;//Нижний и верхний пределы интегрирования (a, b), погрешность (eps).
	cout << "Введите начало отрезка: ";
	cin >> a;
	cout << "Введите конец отрезка: ";
	cin >> b;
	cout << "Введите погрешность интегрирования: ";
	cin >> eps;
	double I = eps + 1, I1 = 0;//I-предыдущее вычисленное значение интеграла, I1-новое, с большим N.
	for (int N = 2; (N <= 4) || (fabs(I1 - I) > eps); N *= 2)
	{
		double h, sum2 = 0, sum4 = 0, sum = 0;
		h = (b - a) / (2 * N);//Шаг интегрирования.
		for (int i = 1; i <= 2 * N - 1; i += 2)
		{
			sum4 += f(a + h * i);//Значения с нечётными индексами, которые нужно умножить на 4.
			sum2 += f(a + h * (i + 1));//Значения с чётными индексами, которые нужно умножить на 2.
		}
		sum = f(a) + 4 * sum4 + 2 * sum2 - f(b);//Отнимаем значение f(b) так как ранее прибавили его дважды. 
		I = I1;
		I1 = (h / 3)*sum;
	}
	cout << "Результат интегрирования: " << I1 << endl;
	return 0;
}