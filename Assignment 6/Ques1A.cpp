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

class CircularLinkedList
{
    Node *head;

public:
    CircularLinkedList() { head = nullptr; }

    void insert(int val, int after = -1, bool before = false)
    {
        Node *newNode = new Node(val);

        if (!head)
        { // empty list
            head = newNode;
            head->next = head;
            return;
        }

        if (after == -1)
        { // insert at end
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            return;
        }

        Node *temp = head;
        do
        {
            if (temp->data == after)
            {
                if (before)
                {
                    // find previous node
                    Node *prev = head;
                    while (prev->next != temp)
                        prev = prev->next;
                    prev->next = newNode;
                    newNode->next = temp;
                    if (temp == head)
                        head = newNode;
                }
                else
                {
                    newNode->next = temp->next;
                    temp->next = newNode;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node with value " << after << " not found.\n";
    }

    void deleteNode(int key)
    {
        if (!head)
            return;

        Node *curr = head, *prev = nullptr;

        // If head node itself holds the key
        if (head->data == key && head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        // Find the node
        do
        {
            if (curr->data == key)
            {
                if (curr == head)
                {
                    Node *last = head;
                    while (last->next != head)
                        last = last->next;
                    head = head->next;
                    last->next = head;
                    delete curr;
                }
                else
                {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Node not found!\n";
    }

    void search(int key)
    {
        if (!head)
            return;
        Node *temp = head;
        int pos = 1;
        do
        {
            if (temp->data == key)
            {
                cout << "Node found at position " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void display()
    {
        if (!head)
        {
            cout << "List empty.\n";
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << " (repeat head)\n";
    }
};

int main()
{
    CircularLinkedList cll;
    int choice, val, key;

    while (true)
    {
        cout << "\n*** Circular Linked List Menu ***\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n0. Exit\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            cout << "Insert after which value (-1 for end)? ";
            cin >> key;
            cll.insert(val, key);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            cll.deleteNode(val);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            cll.search(val);
            break;
        case 4:
            cll.display();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid!\n";
        }
    }
}