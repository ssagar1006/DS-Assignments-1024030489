class LowerTriangularMatrix
{
    int *arr;
    int n;

public:
    LowerTriangularMatrix(int size)
    {
        n = size;
        arr = new int[n * (n + 1) / 2];
    }

    int index(int i, int j)
    {
        return (i * (i - 1)) / 2 + (j - 1);
    }

    void set(int i, int j, int value)
    {
        if (i >= j)
            arr[index(i, j)] = value;
    }

    int get(int i, int j)
    {
        return (i >= j) ? arr[index(i, j)] : 0;
    }

    ~LowerTriangularMatrix()
    {
        delete[] arr;
    }
};