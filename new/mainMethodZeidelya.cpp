#include <fstream>
#include <stdio.h>
#include "ReadAndWriteMatrix.h"
#include "Matrix_Solution.h"
#include "Convergence_of_the_Matrix.h"
#include "Matrix_Transformation.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{

	setlocale(LC_ALL, "Rus");
	double epsi = 0.0;
	cout << "Введите желаемую точность:   ";
	char ch1;
	do
	{
		cin >> epsi;
		if (cin.fail())
		{
			cin.clear();
			cin >> ch1;
			cout << "Ошибка ввода точности" << endl;
			exit(2323);
		}
		else
		{
			cout << "Введена корректная точность" << endl;
			break;
		}

	} while (epsi != 0);
	
	int d;
	cout << "Введите размер матрицы: ";
	cin >> d;
	int k = d + 1;
	if (d == 5 || d == 6)
		cout << "Введён корректный размер СЛАУ для проверки." << endl;
	else
	{
		cout << "Некорректный размер СЛАУ для проверки." << endl;
		exit(-10);
	}
	readmatrix::ReadMatrix Matrix(d);
	cout << (!Matrix.Read_WriteMatrix(d, k) ? "Считано до конца." : "Не считано до конца.") << endl;
	Transformation_Matrix MatrixTrans(d);
	cout << "Преобразованная матрица:" << endl;
	MatrixTrans.Transformation(d, Matrix);
	cout << "Проверка матрицы на сходимость:  " ;
	Converge MatrixConv(d);
	MatrixConv.convergence_of_the_Matrix(d, Matrix, MatrixTrans, epsi);
	cin.get();
	return 0;
}