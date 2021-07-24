#if !defined MATRIX_TRANSFORMATION_H
#define MATRIX_TRANSFORMATION_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Matrix_Transformation.h"
#include <cmath>	
#include <iomanip>


using std::cin;
using std::cout;
using std::endl;
using std::string;


class Transformation
	{
		double eps;
		double max;
		double var;
		int count;
		double deps;
		int counter;
		std::vector<double> X;
		std::vector<double> P;
	public:
		void Solution(int n, double epsilon, Transformation_Matrix MatrixTrans);
		Transformation(int n=5):eps(0),max(0),var(0),count(0),deps(0),counter(0)
		{
			X.resize(n);
			P.resize(n);
		}
	};


#endif

