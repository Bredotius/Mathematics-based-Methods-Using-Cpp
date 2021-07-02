//Numerical differentiation describes algorithms for estimating the derivative of a mathematical function or 
//function subroutine using values of the function and perhaps other knowledge about the function.

#include "pch.h"
#include <iostream>

double f(double x)//основная функция
{
	return (sin(2 * x) + cos(x + 1));
}

int main()
{
	setlocale(LC_ALL, "Rus");
    std::cout << "Hello World!\n"; 
	float h = 0.01;//шаг дифференцирования
	int x;
	std::cout << " Введите точку х в которой нужно найти производную: ";
	std::cin >> x;//
	float right = (f(x+h)-f(x))/h;//правосторонняя разность
	float left = (f(x) - f(x-h)) / h;//левосторонняя разность
	float both = (f(x+h) - f(x - h)) / (2*h);//двусторонняя разность
	std::cout << " Значение производной в точке x: \n 1.Способ левосторонней разности: " << 
	left << "\n 2.Способ правосторонней разности: " << 
	right << "\n 3.Способ двусторонней разности: " << both << std::endl;
	return 0;
}