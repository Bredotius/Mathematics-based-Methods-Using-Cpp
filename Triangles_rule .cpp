//The product of diagonal elements and product of elements in the both vertex of two
//triangles of the first determinant get the “+” sign and the product of diagonal
//elements and product of elements in the both vertex of two triangles of the second
//determinant get the “-” sign.

#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std;
const int in = 5;//Размерность матрицы

int main()
{
	SetConsoleOutputCP(1251);//Подключение русского языка
	int i, j, k;
	float d, opr = 1;
	float a[in][in] = { { 1,5,-3,2,3 }, { 2,3,2,3,0 }, { 3,0,2,1,1 }, { 5,2,-2,3,2 }, { 5,-3,-2,0,3 } };
	//Вывод исходной матрицы:
	cout << "Исходная матрица:" << endl;
	for (i = 0; i < in; i++)
	{
		for (j = 0; j < in; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	//Замена строк если 1 эллемент == 0:
	if (a[0][0] == 0)
	{
		for (k = 1; a[k][0] == 0;)//Цикл выбор строки где 1 элемент не равен 0
			k++;
		for (i = 0, j = 0; j < in; j++)//Цикл замены элементов строк
		{
			d = a[i][j];
			a[i][j] = a[k][j];
			a[k][j] = d;
		}
		opr = -1;//Замена знака определителя, т.к. были поменены строки местами
	}
	//Приведение матрицы к верхнему треугольному виду:
	for (k = 0; k < in - 1; k++)
	{
		i = k + 1;
		for (; i < in; i++)
		{
			d = -a[i][k] / a[k][k];
			for (j = 0; j < in; j++)
				a[i][j] = a[i][j] + a[k][j] * d;
		}
	}
	//Вычисление определителя (перемножение элементов главной диагонали):
	for (i = 0; i < in; i++)
		opr = opr * a[i][i];

	//Вывод полученной матрицы:
	cout << endl << "Полученная матрица треугольного вида:" << endl;
	for (i = 0; i < in; i++)
	{
		for (j = 0; j < in; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	//Вывод определителя:
	cout << endl << "Определитель = " << opr << endl;
	system("pause");
	return 0;
}