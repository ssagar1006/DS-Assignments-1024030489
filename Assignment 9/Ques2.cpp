#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> heap; // max heap

    void heapifyUp(int idx)
    {
        int parent = (idx - 1) / 2;
        while (idx > 0 && heap[idx] > heap[parent])
        {
            swap(heap[idx], heap[parent]);
            idx = parent;
            parent = (idx - 1) / 2;
        }
    }

    void heapifyDown(int idx)
    {
        int n = heap.size();
        int largest = idx;

        while (true)
        {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != idx)
            {
                swap(heap[idx], heap[largest]);
                idx = largest;
            }
            else
                break;
        }
    }

public:
    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getMax()
    {
        if (heap.empty())
        {
            cout << "Heap is empty!\n";
            return -1;
        }
        return heap[0];
    }

    int extractMax()
    {
        if (heap.empty())
        {
            cout << "Heap is empty!\n";
            return -1;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    void display()
    {
        cout << "Priority Queue (Max Heap): ";
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(40);
    pq.insert(20);
    pq.insert(60);

    pq.display();

    cout << "Max Element: " << pq.getMax() << endl;

    cout << "Extracted Max: " << pq.extractMax() << endl;

    pq.display();

    return 0;
}