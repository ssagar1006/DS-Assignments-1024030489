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

int deleteAllOccurrences(Node *&head, int key)
{
    int count = 0;
    while (head && head->data == key)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node *curr = head;
    while (curr && curr->next)
    {
        if (curr->next->data == key)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        }
        else
            curr = curr->next;
    }
    return count;
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
    int n, val, key;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertEnd(head, val);
    }
    cout << "Enter key to delete: ";
    cin >> key;

    int cnt = deleteAllOccurrences(head, key);
    cout << "Occurrences deleted: " << cnt << endl;
    display(head);
}