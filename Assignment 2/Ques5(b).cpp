class TriDiagonalMatrix
{
    int *arr;
    int n;

public:
    TriDiagonalMatrix(int size)
    {
        n = size;
        arr = new int[3 * n - 2];
    }

    void set(int i, int j, int value)
    {
        if (i - j == 1)
            arr[i - 2] = value; // Lower diagonal
        else if (i == j)
            arr[n - 1 + i - 1] = value; // Main diagonal
        else if (j - i == 1)
            arr[2 * n - 1 + i - 1] = value; // Upper diagonal
    }

    int get(int i, int j)
    {
        if (i - j == 1)
            return arr[i - 2];
        else if (i == j)
            return arr[n - 1 + i - 1];
        else if (j - i == 1)
            return arr[2 * n - 1 + i - 1];
        else
            return 0;
    }

    ~TriDiagonalMatrix()
    {
        delete[] arr;
    }
};