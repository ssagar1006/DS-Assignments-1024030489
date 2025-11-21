#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &a, int n, int i, bool maxHeap)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (maxHeap)
    {
        if (left < n && a[left] > a[largest])
            largest = left;
        if (right < n && a[right] > a[largest])
            largest = right;
    }
    else
    {
        if (left < n && a[left] < a[largest])
            largest = left;
        if (right < n && a[right] < a[largest])
            largest = right;
    }

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest, maxHeap);
    }
}

void heapSort(vector<int> &a, bool increasing)
{
    int n = a.size();
    bool maxHeap = increasing; // true for increasing order

    // Build Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i, maxHeap);

    // Extract elements
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0, maxHeap);
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "\nOriginal Array:\n";
    for (int x : arr)
        cout << x << " ";

    vector<int> inc = arr;
    heapSort(inc, true);
    cout << "\n\nSorted Increasing (HeapSort):\n";
    for (int x : inc)
        cout << x << " ";

    vector<int> dec = arr;
    heapSort(dec, false);
    cout << "\n\nSorted Decreasing (HeapSort):\n";
    for (int x : dec)
        cout << x << " ";

    return 0;
}