#include <iostream>
using namespace std;

class DNode
{
public:
    int data;
    DNode *next;
    DNode *prev;
    DNode(int val)
    {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyLinkedList
{
    DNode *head;

public:
    DoublyLinkedList() { head = nullptr; }

    void insert(int val, int after = -1, bool before = false)
    {
        DNode *newNode = new DNode(val);
        if (!head)
        {
            head = newNode;
            return;
        }

        if (after == -1)
        { // insert at end
            DNode *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            return;
        }

        DNode *temp = head;
        while (temp && temp->data != after)
            temp = temp->next;

        if (!temp)
        {
            cout << "Node not found!\n";
            return;
        }

        if (before)
        {
            newNode->prev = temp->prev;
            newNode->next = temp;
            if (temp->prev)
                temp->prev->next = newNode;
            else
                head = newNode;
            temp->prev = newNode;
        }
        else
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next)
                temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    void deleteNode(int key)
    {
        if (!head)
            return;
        DNode *temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp)
        {
            cout << "Node not found!\n";
            return;
        }

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
    }

    void search(int key)
    {
        DNode *temp = head;
        int pos = 1;
        while (temp)
        {
            if (temp->data == key)
            {
                cout << "Node found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }

    void display()
    {
        DNode *temp = head;
        while (temp)
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};