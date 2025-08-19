class SymmetricMatrix
{
    int *arr;
    int n;

public:
    SymmetricMatrix(int size)
    {
        n = size;
        arr = new int[n * (n + 1) / 2];
    }

    int index(int i, int j)
    {
        if (i > j){
            int temp = i;
            i = j;
            j = temp;
        }
        return (i - 1) * n - ((i - 2) * (i - 1)) / 2 + (j - i);
    }

    void set(int i, int j, int value)
    {
        arr[index(i, j)] = value;
    }

    int get(int i, int j)
    {
        return arr[index(i, j)];
    }

    ~SymmetricMatrix()
    {
        delete[] arr;
    }
};