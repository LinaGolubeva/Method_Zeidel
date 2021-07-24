#include "Matrix_Solution.h"


void Transformation::Solution(int n, double epsilon, Transformation_Matrix MatrixTrans)
{
    deps = epsilon;
    
    while (deps != 1)
    {
        deps *= 10;
        count++;
    }
    do
    {
        P = X;
        counter++;
        cout << "Итерация № " << counter << endl << endl;
        for (int i = 0; i < n; i++)
        {
            var = 0;
            for (int j = 0; j < n; j++)
                var += (MatrixTrans.get_MatrixB1().at(i).at(j) * X.at(j))+ (MatrixTrans.get_MatrixB2().at(i).at(j) * P.at(j));
            X.at(i) = MatrixTrans.get_MatrixB().at(i) + var;
        }
        max = 0;
        for (int i = 0; i < n; i++)
        {
            max += (X.at(i) - P.at(i)) * (X.at(i) - P.at(i));
            cout << std::fixed<< std::setprecision(count) <<   "X" << i + 1 << " = " << X.at(i) << " " << endl;
        }
       max=sqrt(max);
       cout << endl;
    } while ((int)(max*pow(10.0,count))/pow(10.0, count) > eps);
  
    cout << endl << "Результат: \n\n";
    for (int i = 0; i < n; i++)
        cout << "X" << i + 1 << "=" << X.at(i) << " " << endl;

    std::ofstream outputFile("out.txt");
    for (int i = 0; i < n; i++)
    {
        
        outputFile<< std::fixed<<std::setprecision(count) << X.at(i) << endl;
    }
    
    outputFile.close();
}