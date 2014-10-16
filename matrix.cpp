#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include "matrix.h"
using namespace std;
int menu();
int menu()
{
	int i;
	cout << "Выберите действие которое хотите совершить" << endl;
	cout << "0.Создание матрицы" << endl;
	cout << "1.Изменение числа строк в матрице" << endl;
	cout << "2.Изменение числа столбцов в матрице" << endl;
	cout << "3.Загрузка матрицы из файла" << endl;
	cout << "4.Извлечение подматрицы заданного размера" << endl;
	cout << "5.Проверка типа матрицы" << endl;
	cout << "6.Транспонирование матрицы" << endl;
	cout << "7.Выход" << endl;
	cin >> i;
	return i;
}
int menu1()
{
	int i;
	cout << "Выберите действие которое хотите совершить" << endl;
	cout << "1.Изменить число строк " << endl;
	cout << "2.Измененить число стоблцов" << endl;
	cin >> i;
	return i;
}
int menu2()
{
	int i;
	cout << "Выберите действие которое хотите совершить" << endl;
	cout << "1.Добавить заданное число строк " << endl;
	cout << "2.Удалить заданное число строк" << endl;
	cout << "3.Выйти из данного меню" << endl;
	cin >> i;
	return i;
}
int menu3()
{
	int i;
	cout << "Выберите действие которое хотите совершить" << endl;
	cout << "1.Добавить заданное число столбцов" << endl;
	cout << "2.Удалить заданное число столбцов" << endl;
	cout << "3.Выйти из данного меню" << endl;
	cin >> i;
	return i;
}
int main()
{
	matrix a;
	int z, v;
	setlocale(LC_ALL, "Rus");
	cout << "Введите число строк матрицы: ";
	cin >> a.n;
	cout << "Введите число столбцов матрицы: ";
	cin >> a.m;
	/*int **matrix = new int*[a.m];
	for (int d = 0; d < a.m; d++)
	matrix[d] = new int[a.n];
	for (int s = 0; s < a.n; s++)
	{
	for (int x = 0; x < a.m; x++)
	matrix[s][x] = 0;
	}
	for (int s = 0; s < a.n; s++)
	{
	for (int x = 0; x < a.m; x++)
	{
	cout << "Введите элемент " << "[" << s + 1 << "]" << "[" << x + 1 << "] : ";
	cin >> z;
	matrix[s][x] = z;
	}
	}*/
	
	
	while (true)
	{
		switch (menu())
		{
		case 0:{a.sozdanie();
			for (int s = 0; s < a.n; s++)
			{
				for (int x = 0; x < a.m; x++)
				{
					cout << "Введите элемент " << "[" << s + 1 << "]" << "[" << x + 1 << "] : ";
					cin >> z;
					a.matrix1[s][x] = z;
				}
			}
			for (int c = 0; c < a.n; c++)
			{
				for (int v = 0; v < a.m; v++)
				{
					cout << a.matrix1[c][v] << " ";
				}
				cout << endl;
			}
		}

			break;
		case 1:{while (true)
		{
				   switch (menu1())
				   {
				   case 1: {
							   switch (menu2())
							   {
							   case 1:{
										  cout << "Введите число строк которое желаете добавить";
										  cin >> a.n1;
										  cout << "Введите номер строки после которой желаете добавить новую строку";
										  cin >> a.w; 
										  v = a.n1*a.m;
										  a.mas = new int[v];
										  cout << "Введите элементы который хотите добавить в матрицу, вводить обязательно попорядку слева направо";
										  for (int d = 0; d < v; d++)
										  {
											  cin >> z;
											  a.mas[d] = z;
										  }
										  a.izmenenie1(a.matrix1, a.mas);
										  for (int c = 0; c < a.n+a.n1; c++)
										  {
											  for (int v = 0; v < a.m; v++)
											  {
												  cout << a.matrix2[c][v] << " ";
											  }
											  cout << endl;
										  }
										  delete []a.mas;
							   }break;
							   case 2: {
										   cout << "Введите кол-во строк, котроое вы хотите удалить" << endl;
										   cin >> a.n1;
										   cout << "Ведите строку после которой хотите удалить строки" << endl;
										   cin >> a.w;
										   a.delete1(a.matrix1);
										   for (int c = 0; c < a.n-a.n1; c++)
										   {
											   for (int v = 0; v < a.m; v++)
											   {
												   cout << a.matrix2[c][v] << " ";
											   }
											   cout << endl;
										   }
							   }break;
							   }
				   }
				   case 2:{
				   
							  switch (menu3())
							  {
							  case 1:{
										 cout << "Введите число столбцов которое желаете добавить";
										 cin >> a.m1;
										 cout << "Введите номер столбца после которой желаете добавить новую строку";
										 cin >> a.w; 
										 v = a.m1*a.n;
										 a.mas = new int[v];
										 cout << "Введите элементы который хотите добавить в матрицу, вводить обязательно попорядку слева направо";
										 for (int d = 0; d < v; d++)
										 {
											 cin >> z;
											 a.mas[d] = z;
										 }
										 a.izmenenie2(a.matrix1, a.mas);
										 for (int c = 0; c < a.n ; c++)
										 {
											 for (int v = 0; v < a.m1+a.m; v++)
											 {
												 cout << a.matrix2[c][v] << " ";
											 }
											 cout << endl;
										 }
										 delete[]a.mas;
							  }break;
							  case 2:break;
							  }
				   }
				   }
					   break;

				   }
		}
					   //a.izmenenie1(a.matrix1);
					   break;
				   case 5:{
							  if (a.tip(a.matrix1) == 1)
								  cout << "Матрица нулевая" << endl;
							  if (a.tip1(a.matrix1) == 1)
								  cout << "Матрица квадратная" << endl;
							  if (a.tip2(a.matrix1) == 1)
								  cout << "Матриа единичная" << endl;
							  if (a.tip3(a.matrix1) == 1)
								  cout << "Мартица симметричная" << endl;
							  if (a.tip4(a.matrix1) == 1)
								  cout << "Мартица диагональная" << endl;
							  if (a.tip5(a.matrix1) == 1)
								  cout << "Матрица верхняя треугольная" << endl;
							  if (a.tip6(a.matrix1) == 1)
								  cout << "Матрица нижняя треугольная" << endl;
				   }
					   break;
				   case 6:{a.trancpon(a.matrix1);
					   for (int c = 0; c < a.m; c++)
					   {
						   for (int v = 0; v < a.n; v++)
						   {
							   cout << a.trans[c][v] << " ";
						   }
						   cout << endl;
					   }}
					   break;
				   case 7:return 0;
				   }
		}
		

			return 0;
		}
