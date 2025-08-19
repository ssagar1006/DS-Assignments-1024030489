#include <iostream>
using namespace std;

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right)
{
    long long inv_count = 0;
    int i = left;    // Left subarray
    int j = mid + 1; // Right subarray
    int k = left;    // Merged array

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // All remaining elements in left are greater
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

long long countInversions(int arr[], int temp[], int left, int right)
{
    long long inv_count = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        inv_count += countInversions(arr, temp, left, mid);
        inv_count += countInversions(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    int *temp = new int[n];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    long long inversions = countInversions(arr, temp, 0, n - 1);
    cout << "Number of inversions: " << inversions << endl;

    delete[] arr;
    delete[] temp;
    return 0;
}