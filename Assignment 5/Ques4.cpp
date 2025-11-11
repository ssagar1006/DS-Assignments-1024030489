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

Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void display(Node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
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
    cout << "Original List: ";
    display(head);
    head = reverse(head);
    cout << "Reversed List: ";
    display(head);
}