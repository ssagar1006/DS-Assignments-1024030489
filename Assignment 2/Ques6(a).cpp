#include <iostream>
using namespace std;

struct Element
{
    int row, col, value;
};

class SparseMatrix
{
    Element *data;
    int rows, cols, numNonZero;

public:
    SparseMatrix(int r, int c, int nz)
    {
        rows = r;
        cols = c;
        numNonZero = nz;
        data = new Element[nz];
    }

    void input()
    {
        cout << "Enter non-zero elements (row col value):\n";
        for (int i = 0; i < numNonZero; ++i)
        {
            cin >> data[i].row >> data[i].col >> data[i].value;
        }
    }

    void display()
    {
        cout << "Sparse Matrix (Triplet Format):\n";
        cout << "Row\tCol\tValue\n";
        for (int i = 0; i < numNonZero; ++i)
        {
            cout << data[i].row << "\t" << data[i].col << "\t" << data[i].value << endl;
        }
    }

    SparseMatrix transpose()
    {
        SparseMatrix result(cols, rows, numNonZero);
        int k = 0;
        for (int i = 0; i < cols; ++i)
        {
            for (int j = 0; j < numNonZero; ++j)
            {
                if (data[j].col == i)
                {
                    result.data[k].row = data[j].col;
                    result.data[k].col = data[j].row;
                    result.data[k].value = data[j].value;
                    ++k;
                }
            }
        }
        return result;
    }

    SparseMatrix add(SparseMatrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw runtime_error("Matrix dimensions must match for addition.");
        }

        SparseMatrix result(rows, cols, numNonZero + other.numNonZero);
        int i = 0, j = 0, k = 0;

        while (i < numNonZero && j < other.numNonZero)
        {
            if (data[i].row < other.data[j].row ||
                (data[i].row == other.data[j].row && data[i].col < other.data[j].col))
            {
                result.data[k++] = data[i++];
            }
            else if (data[i].row > other.data[j].row ||
                     (data[i].row == other.data[j].row && data[i].col > other.data[j].col))
            {
                result.data[k++] = other.data[j++];
            }
            else
            {
                int sum = data[i].value + other.data[j].value;
                if (sum != 0)
                {
                    result.data[k].row = data[i].row;
                    result.data[k].col = data[i].col;
                    result.data[k].value = sum;
                    ++k;
                }
                ++i;
                ++j;
            }
        }

        while (i < numNonZero)
            result.data[k++] = data[i++];
        while (j < other.numNonZero)
            result.data[k++] = other.data[j++];

        result.numNonZero = k;
        return result;
    }

    SparseMatrix multiply(SparseMatrix &other)
    {
        if (cols != other.rows)
        {
            throw runtime_error("Matrix dimensions incompatible for multiplication.");
        }

        SparseMatrix otherT = other.transpose();
        SparseMatrix result(rows, other.cols, rows * other.cols); // max possible

        int k = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < other.cols; ++j)
            {
                int sum = 0;
                for (int a = 0; a < numNonZero; ++a)
                {
                    if (data[a].row == i)
                    {
                        for (int b = 0; b < otherT.numNonZero; ++b)
                        {
                            if (otherT.data[b].row == j && data[a].col == otherT.data[b].col)
                            {
                                sum += data[a].value * otherT.data[b].value;
                            }
                        }
                    }
                }
                if (sum != 0)
                {
                    result.data[k].row = i;
                    result.data[k].col = j;
                    result.data[k].value = sum;
                    ++k;
                }
            }
        }

        result.numNonZero = k;
        return result;
    }

    ~SparseMatrix()
    {
        delete[] data;
    }
};