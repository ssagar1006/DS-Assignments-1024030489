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

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAfterValue(int key, int val)
    {
        Node *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (temp == nullptr)
        {
            cout << "Key not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertBeforeValue(int key, int val)
    {
        if (head == nullptr)
            return;
        if (head->data == key)
        {
            insertAtBeginning(val);
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;
        if (temp->next == nullptr)
        {
            cout << "Key not found!\n";
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteSpecific(int key)
    {
        if (head == nullptr)
            return;
        if (head->data == key)
        {
            deleteFromBeginning();
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;
        if (temp->next == nullptr)
        {
            cout << "Key not found!\n";
            return;
        }
        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void search(int key)
    {
        Node *temp = head;
        int pos = 1;
        while (temp)
        {
            if (temp->data == key)
            {
                cout << "Node found at position: " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    LinkedList list;
    int choice, val, key;

    while (true)
    {
        cout << "\n*** MENU ***\n";
        cout << "1. Insert at beginning\n2. Insert at end\n3. Insert before value\n4. Insert after value\n";
        cout << "5. Delete from beginning\n6. Delete from end\n7. Delete specific node\n8. Search\n9. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key and value: ";
            cin >> key >> val;
            list.insertBeforeValue(key, val);
            break;
        case 4:
            cout << "Enter key and value: ";
            cin >> key >> val;
            list.insertAfterValue(key, val);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Enter key: ";
            cin >> key;
            list.deleteSpecific(key);
            break;
        case 8:
            cout << "Enter key: ";
            cin >> key;
            list.search(key);
            break;
        case 9:
            list.display();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}