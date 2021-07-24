#if !defined READ_MATRIX_FILE
#define READ_MATRIX_FILE

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace readmatrix
{
	const string sMATRIX_FILE_NAME1("Matrix_5.txt");
	const string sMATRIX_FILE_NAME2("Matrix_6.txt");
	static std::ifstream in;
	class ReadMatrix
	{
		std::vector<std::vector<double>> WriteMatrix;
	public:
		ReadMatrix(int n)
		{
			WriteMatrix.resize(n);
			for (int i = 0; i < n; i++)
			{
				WriteMatrix.at(i).resize(n+1);
			}
		}
		int Read_WriteMatrix(int, int);
		std::vector<std::vector<double>>& get_WriteMatrix()
		{
			return WriteMatrix;
		}
	};

}
#endif


