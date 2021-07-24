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
	cout << "������� �������� ��������:   ";
	char ch1;
	do
	{
		cin >> epsi;
		if (cin.fail())
		{
			cin.clear();
			cin >> ch1;
			cout << "������ ����� ��������" << endl;
			exit(2323);
		}
		else
		{
			cout << "������� ���������� ��������" << endl;
			break;
		}

	} while (epsi != 0);
	
	int d;
	cout << "������� ������ �������: ";
	cin >> d;
	int k = d + 1;
	if (d == 5 || d == 6)
		cout << "����� ���������� ������ ���� ��� ��������." << endl;
	else
	{
		cout << "������������ ������ ���� ��� ��������." << endl;
		exit(-10);
	}
	readmatrix::ReadMatrix Matrix(d);
	cout << (!Matrix.Read_WriteMatrix(d, k) ? "������� �� �����." : "�� ������� �� �����.") << endl;
	Transformation_Matrix MatrixTrans(d);
	cout << "��������������� �������:" << endl;
	MatrixTrans.Transformation(d, Matrix);
	cout << "�������� ������� �� ����������:  " ;
	Converge MatrixConv(d);
	MatrixConv.convergence_of_the_Matrix(d, Matrix, MatrixTrans, epsi);
	cin.get();
	return 0;
}