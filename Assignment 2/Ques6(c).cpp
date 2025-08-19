#include <iostream>
using namespace std;

int main()
{
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter rows and columns of Matrix B: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB)
    {
        cout << "Oops! Can't multiply these two matrices." << endl;
        return 0;
    }

    int A[50][50], B[50][50], C[50][50];

    cout << "\nEnter elements of Matrix A (" << rowsA << "x" << colsA << "):\n";
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            cin >> A[i][j];

    cout << "\nEnter elements of Matrix B (" << rowsB << "x" << colsB << "):\n";
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++)
            cin >> B[i][j];

    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++)
        {
            int sum = 0;
            for (int k = 0; k < colsA; k++)
                sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }

    cout << "\nResultant Matrix (C):\n";
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
            cout << C[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
