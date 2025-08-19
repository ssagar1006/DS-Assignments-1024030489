#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int A[100][100], B[100][100], sum[100][100];

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
    cout << "Sum of matrices:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
