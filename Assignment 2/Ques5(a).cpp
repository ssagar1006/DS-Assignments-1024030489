class DiagonalMatrix
{
    int *arr;
    int n;

public:
    DiagonalMatrix(int size)
    {
        n = size;
        arr = new int[n];
    }

    void set(int i, int j, int value)
    {
        if (i == j)
            arr[i - 1] = value;
    }

    int get(int i, int j)
    {
        return (i == j) ? arr[i - 1] : 0;
    }

    ~DiagonalMatrix()
    {
        delete[] arr;
    }
};