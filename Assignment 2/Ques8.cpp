#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    unordered_set<int> distinctElements;
    for (int i = 0; i < n; ++i)
    {
        distinctElements.insert(arr[i]);
    }

    cout << "Total number of distinct elements: " << distinctElements.size() << endl;

    delete[] arr;
    return 0;
}