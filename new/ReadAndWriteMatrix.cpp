
#include "ReadAndWriteMatrix.h"

//std::vector<std::vector<double>> readmatrix::ReadMatrix::WriteMatrixA25;
int readmatrix::ReadMatrix::Read_WriteMatrix(int n, int m)
{
	if (n == 5)
		in.open(sMATRIX_FILE_NAME1.c_str());
	else in.open(sMATRIX_FILE_NAME2.c_str());
	double write = 0;
	int count = 0;
	string x = (n == 5) ? sMATRIX_FILE_NAME1 : sMATRIX_FILE_NAME2;
	if (readmatrix::in.is_open())
	{
		while (!readmatrix::in.eof())
		{
			readmatrix::in >> write;
			count++;
		}
	}
	else
	{
		cout << "���� " << x << " �� ������" << endl;
		exit(1);
	}
	if (count >= n * (n + 1))
	{
		cout << "���� " << x << " �������� ����������� ���������� ���������." << endl << endl;;
	}
	else
	{
		cout << "���� " << x << " �������� ������������� ���������� ���������. ���������� ��������� � ����� : " << count << endl << endl;
		exit(89);
	}
	readmatrix::in.clear();
	readmatrix::in.seekg(0, std::ios::beg);
	cout << "�������� ����" << endl;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(10);
			readmatrix::in >> write;
			WriteMatrix.at(i).at(j)=write;
			cout << WriteMatrix.at(i).at(j) << "   ";
		}
		cout << endl;
	}
	in.close();
	return  0;
}

