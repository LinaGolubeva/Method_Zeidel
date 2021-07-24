#include "Convergence_of_the_Matrix.h"

void Converge::convergence_of_the_Matrix(int n, readmatrix::ReadMatrix Matrix, Transformation_Matrix MatrixTrans, double epsi)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            double sum = 0;
            sum += fabs(MatrixTrans.get_MatrixB1().at(i).at(j)) + fabs(MatrixTrans.get_MatrixB2().at(i).at(j));
            if (sum > norm) norm = sum;
        }
    }
    if (norm >= 1)
    {
        double  d = Determinant(Matrix.get_WriteMatrix(), n);
        if (d == 0)
        {
            cout << "Детерминант равен 0. Условия сходимости не выполняются." << endl;
            exit(-231);
        }
        else
        {
            cout << "Норма матрицы больше или равна 1. Выполняем заново преобразование матрицы:" << endl;
            SimmetricMatrix(Matrix.get_WriteMatrix(), n);
            Transformation_Matrix Matrix_new;
            Matrix_new.Transformation_Matrix::Transformation(n, Matrix);
            cout << "Решение СЛАУ методом Зейделя: " << endl;
            Transformation MatrixSol;
            MatrixSol.Solution(n, epsi, Matrix_new);
        }
    }
    else
    {
        cout << "Норма матрицы меньше 1." << endl;
        cout << "Решение СЛАУ методом Зейделя: " << endl;
        Transformation MatrixSol(n);
        MatrixSol.Solution(n, epsi, MatrixTrans);
    }
}
void Converge::GetMatr(std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& b, int j, int i, int m)
{
    int dj = 0;
    int di = 0;
    for (int ki = 0; ki < m - 1; ki++)
    {
        if (ki == i)
            di = 1;
        dj = 0;
        for (int kj = 0; kj < m - 1; kj++)
        {
            if (kj == j)
                dj = 1;
            b.at(ki).at(kj) = A.at(ki + di).at(kj + dj);
        }
    }
}

double Converge::Determinant(std::vector<std::vector<double>>& A, int m)
{
    std::vector<std::vector<double>> MatDet;
    double d = 0.0;
    int k = 1;
    if (m == 1)
    {
        return A.at(0).at(0);
    }
    else if (m == 2)
    {
        return A.at(0).at(0) * A.at(1).at(1) - (A.at(1).at(0) * A.at(0).at(1));
    }
    else
    {
        MatDet.resize(m - 1);
        for (int i = 0; i < m - 1; i++)
            MatDet.at(i).resize(m - 1);
        for (int j = 0; j < m; j++)
        {
            GetMatr(A, MatDet, j, 0, m);
            d += k * A.at(0).at(j) * Determinant(MatDet, m - 1);
            k = -k;
        }
    }
    return d;
}

void Converge::SimmetricMatrix(std::vector<std::vector<double>>& A, int n)
{
    std::vector< std::vector<double>> TransMatrix(n, std::vector<double>(n + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            TransMatrix.at(i).at(j) = A.at(i).at(j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A.at(i).at(j) = 0.0;
            for (int k = 0; k < n; k++)
                A.at(i).at(j) += TransMatrix.at(i).at(k) * TransMatrix.at(k).at(j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A.at(i).at(n) = 0;
            for (int k = 0; k < n; k++)
                A.at(i).at(n) += TransMatrix.at(i).at(k) * TransMatrix.at(k).at(n);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << A.at(i).at(j) << "    ";
        }
        cout << endl;
    }
}