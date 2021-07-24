#if !defined CONVERGENCE_MATRIX_H
#define CONVERGENCE_MATRIX_H

#include <iostream>
#include <fstream>
#include <vector> 
#include "Matrix_Solution.h"



class Converge
	{
		double norm ;
		bool resultSimmetric;
		void GetMatr(std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& b, int j, int i, int m);
		double Determinant(std::vector<std::vector<double>>& A,int n);
		void SimmetricMatrix(std::vector<std::vector<double>>& A, int n);
	public:
		Converge(int n) :norm(0), resultSimmetric(true){}
		void convergence_of_the_Matrix(int n, readmatrix::ReadMatrix Matrix, Transformation_Matrix MatrixTrans, double epsi);
		
	};
	

#endif