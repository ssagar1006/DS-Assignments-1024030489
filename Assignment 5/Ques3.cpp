#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void insertEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

int findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow ? slow->data : -1;
}

int main()
{
    Node *head = nullptr;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertEnd(head, val);
    }
    cout << "Middle element: " << findMiddle(head) << endl;
}