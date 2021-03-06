//In linear algebra, a minor of a matrix A is the determinant of some smaller square matrix, cut down from A by removing one or more of its rows and columns.

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
const int in = 5;//Размерность матрицы

float opredelitel(float a[in][in], int i, int p)//Функция нахождения определителя методом миноров
{
	float b[in][in];
	float opr = 0;
	int m = 1, k, n, l, v;
	//Нахождение Минора:
	if (p > 2)//Условие если размерность матрицы больше 2
	{
		//Разложение матрицы по эллементам столбца:
		for (n = 0, l = 0; l < p; l++, n++)
		{
			if (l == i)//Переключение на следующую строку если номер строки мат-рицы совпадает с номером строки выбранного элемента
				l++;
			for (k = 1, v = 0; k < p; k++, v++)//Создание матрицы Минора
				b[n][v] = a[l][k];
		}
		p -= 1;//Уменьшение размерности матрицы Минора
		//Нахождение определителя:
		if (p > 2)
		{
			for (i = 0; i < p; i++, m *= -1)//Цикл разложения матрицы по элементам 1 столбца
				opr = opr + b[i][0] * m * opredelitel(b, i, p);
		}
	}
	if (p == 2)//Вычисление определителя если размерность матрицы = 2
	{
		opr = b[0][0] * b[1][1] - b[0][1] * b[1][0];
	}
	return opr;
};
int main()
{
	SetConsoleOutputCP(1251);//Подключение русского языка
	srand(time(0));
	int  i, m, j;
	float a[in][in] = { {3,2,-4,1,1}, {5,-4,-4,5,2 }, {1,1,0,3,2 }, {2,2,-2,4,3}, {1,0,0,2,5} };
	float opr;
	for (i = 0, opr = 0, m = 1; i < in; m *= -1, i++)//Цикл разложения матрицы по элементам 1 столбца
		opr = opr + a[i][0] * m * opredelitel(a, i, in);
	//Вывод исходной матрицы:
	cout << endl << "Исходная матрица:" << endl;
	for (i = 0; i < in; i++)
	{
		for (j = 0; j < in; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	//Вывод определителя:
	cout << endl << "Определитель = " << opr << endl;
	cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы   
	system("pause");
	return 0;
}
