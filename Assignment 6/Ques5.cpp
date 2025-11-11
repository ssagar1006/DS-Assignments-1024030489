#include <iostream>
using namespace std;

class NodeCheck
{
public:
    int data;
    NodeCheck *next;
    NodeCheck(int val)
    {
        data = val;
        next = nullptr;
    }
};

bool isCircular(NodeCheck *head)
{
    if (!head)
        return false;
    NodeCheck *temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main()
{
    NodeCheck *head = new NodeCheck(10);
    head->next = new NodeCheck(20);
    head->next->next = new NodeCheck(30);
    cout << (isCircular(head) ? "Circular" : "Not Circular") << endl;
}