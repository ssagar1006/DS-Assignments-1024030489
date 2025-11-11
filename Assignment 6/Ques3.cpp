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

int sizeDoubly(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

int sizeCircular(Node *head)
{
    if (!head)
        return 0;
    int count = 0;
    Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}
    void insert(int val, int key)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        if (key == -1)
        {
            Node *cur = head;
            while (cur->next)
                cur = cur->next;
            cur->next = newNode;
            return;
        }
        Node *cur = head;
        while (cur && cur->data != key)
            cur = cur->next;
        if (!cur)
        { // key not found -> append
            cur = head;
            while (cur->next)
                cur = cur->next;
            cur->next = newNode;
        }
        else
        {
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
    void deleteNode(int val)
    {
        if (!head)
        {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == val)
        {
            Node *tmp = head;
            head = head->next;
            delete tmp;
            cout << "Deleted " << val << ".\n";
            return;
        }
        Node *prev = head;
        Node *cur = head->next;
        while (cur && cur->data != val)
        {
            prev = cur;
            cur = cur->next;
        }
        if (!cur)
        {
            cout << val << " not found.\n";
            return;
        }
        prev->next = cur->next;
        delete cur;
        cout << "Deleted " << val << ".\n";
    }

    void search(int val)
    {
        Node *cur = head;
        int pos = 0;
        while (cur)
        {
            if (cur->data == val)
            {
                cout << val << " found at position " << pos << ".\n";
                return;
            }
            cur = cur->next;
            pos++;
        }
        cout << val << " not found.\n";
    }
    void display()
    {
        Node *cur = head;
        while (cur)
        {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    DoublyLinkedList dll;
    int choice, val, key;

    while (true)
    {
        cout << "\n*** Doubly Linked List Menu ***\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            cout << "Insert after which value (-1 for end)? ";
            cin >> key;
            dll.insert(val, key);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            dll.deleteNode(val);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            dll.search(val);
            break;
        case 4:
            dll.display();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid!\n";
        }
    }
    return 0;
}