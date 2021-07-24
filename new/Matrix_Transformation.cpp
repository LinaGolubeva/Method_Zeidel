#include "Matrix_Transformation.h"


void Transformation_Matrix::Transformation(int n, readmatrix::ReadMatrix Matrix)
{
   
    MatrixA = Matrix.get_WriteMatrix();
    for (int i = 0; i < n; i++)
    {
        MatrixB.at(i) = Matrix.get_WriteMatrix()[i][n];
    }

    cout << endl;
   
    for (int i = 0; i < n; i++)
    {
        temp = MatrixA.at(i).at(i) * (-1);
        MatrixB.at(i) /= temp;
        for (int j = 0; j < n; j++)
        {
            cout.width(10);
            MatrixA.at(i).at(j) /= temp;
            MatrixA.at(i).at(i) = fabs(0.0);
            cout << MatrixA.at(i).at(j) << "     ";
        }
        cout << endl;
    }

    cout << endl << "Столбец В" << endl;

    for (int i = 0; i < n; i++)
    {
        cout.width(10);
        MatrixB.at(i) *= -1;
        cout << MatrixB.at(i) << endl;
    }

    cout << endl;
    
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (j < i)
                MatrixB1.at(i).at(j) = MatrixA.at(i).at(j);
            else
                MatrixB1.at(i).at(j) = 0.0;
        }
        for (int j = 0; j < n; j++)
        {
            if (j > i)
                MatrixB2.at(i).at(j) = MatrixA.at(i).at(j);
            else
                MatrixB2.at(i).at(j) = 0.0;
        }
    }
}
