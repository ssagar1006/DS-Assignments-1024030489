class UpperTriangularMatrix
{
    int *arr;
    int n;

public:
    UpperTriangularMatrix(int size)
    {
        n = size;
        arr = new int[n * (n + 1) / 2];
    }

    int index(int i, int j)
    {
        return (i - 1) * n - ((i - 2) * (i - 1)) / 2 + (j - i);
    }

    void set(int i, int j, int value)
    {
        if (i <= j)
            arr[index(i, j)] = value;
    }

    int get(int i, int j)
    {
        return (i <= j) ? arr[index(i, j)] : 0;
    }

    ~UpperTriangularMatrix()
    {
        delete[] arr;
    }
};