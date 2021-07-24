#if !defined TRANSFORMATION_H
#define TRANSFORMATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include "ReadAndWriteMatrix.h"

using std::cin;
using std::cout;
using std::endl;


class Transformation_Matrix
	{
		 double temp;
		 std::vector< std::vector<double>> MatrixA;
		 std::vector<double> MatrixB;
		 std::vector<std::vector<double>> MatrixB1;
		 std::vector<std::vector<double>> MatrixB2;
	public:
		Transformation_Matrix(int n=5) :temp(0)
		{
			MatrixA.resize(n);
			MatrixB.resize(n);
			MatrixB1.resize(n);
			MatrixB2.resize(n);
			for (int i = 0; i < n; i++)
			{
				MatrixA.at(i).resize(n);
				MatrixB1.at(i).resize(n);
				MatrixB2.at(i).resize(n);
			}
		}
		void Transformation(int n, readmatrix::ReadMatrix Matrix);
		std::vector<std::vector<double>> const& get_MatrixB1() const
		{
			return MatrixB1;
		}
		void set_MatrixB1(std::vector<std::vector<double>> V)
		{
			MatrixB1 = V;
		}
		std::vector<std::vector<double>> const& get_MatrixB2() const
		{
			return MatrixB2;
		}
		void set_MatrixB2(std::vector<std::vector<double>> V)
		{
			MatrixB2 = V;
		}
		std::vector<double> const& get_MatrixB() const
		{
			return MatrixB;
		}
		void set_MatrixB(std::vector<double> V)
		{
			MatrixB = V;
		}
	};

#endif
