//In linear algebra, the transpose of a matrix is an operator which flips a matrix over its diagonal;
//that is, it switches the row and column indices of the matrix A by producing another matrix, often denoted by AT (among other notations). 

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
const int in = 5;//Размерность матрицы

int main()
{
	setlocale(LC_ALL, "RUS");//Подключение русского языка
	int i, j, k, m;
	float a[in][in] = { { 3,2,-4,1,1}, {5,-4,-4,5,2 }, { 1,1,0,3,2 }, { 2,2,-2,4,3}, { 1,0,0,2,5} };
	float p;
	//Вывод исходной матрицы:
	cout << endl << "Исходная матрица:" << endl;
	for (i = 0; i < in; i++)
	{
		for (j = 0; j < in; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	//Основной цикл работы программы:
	for (m = 0; m < in - 1; i = 0, j = 0, m++)
	{
		i = m + 1;
		j = m;
		for (; i < in; i++)//Вычисление элементов L матрицы по формуле
		{
			for (k = 0, p = 0; k < j; k++)
			{
				p = p + a[i][k] * a[k][j];
			}
			a[i][j] = (a[i][j] - p) / a[j][j];
		}
		for (i = m + 1, j++; j < in; j++)//Вычисление элементов U матрицы по форму-ле
		{
			for (k = 0, p = 0; k < i; k++)
			{
				p = p + a[i][k] * a[k][j];
			}
			a[i][j] = a[i][j] - p;
		}
	}

	float b[in][in];
	//Вывод полученной верхней U матрицы:
	cout << endl << "Верхняя U матрица: " << endl;
	for (i = 0; i < in; i++)
	{
		for (j = 0; j < in; j++)
		{
			if (j < i)
				b[i][j] = 0;
			else
				b[i][j] = a[i][j];
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	//Вывод полученной нижней L матрицы:
	cout << endl << "Нижняя L матрица: " << endl;
	for (i = 0; i < in; i++)
	{
		for (j = 0; j < in; j++)
		{
			if (j == i)
				a[i][j] = 1;
			else if (j > i)
				a[i][j] = 0;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "Время = " << clock() / 1000.0 << endl; // время работы программы 
	system("pause");
	return 0;
}