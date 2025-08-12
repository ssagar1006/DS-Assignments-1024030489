// 1) Implement the Binary search algorithm regarded as a fast search algorithm with run-time
// complexity of Ο(log n) in comparison to the Linear Search.
#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {11, 22, 25, 34, 64, 90}; // Sorted array
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 25;
    int result = binarySearch(arr, n, key);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found.\n");
}
