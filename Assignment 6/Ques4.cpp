#include <iostream>
using namespace std;

class CharNode
{
public:
    char data;
    CharNode *next;
    CharNode *prev;
    CharNode(char c)
    {
        data = c;
        next = prev = nullptr;
    }
};

bool isPalindrome(CharNode *head)
{
    if (!head)
        return true;
    CharNode *end = head;
    while (end->next)
        end = end->next;

    while (head != end && end->next != head)
    {
        if (head->data != end->data)
            return false;
        head = head->next;
        end = end->prev;
    }
    return true;
}

int main()
{
    CharNode *head = nullptr, *temp = nullptr;
    string s;
    cout << "Enter string: ";
    cin >> s;
    for (char c : s)
    {
        CharNode *newNode = new CharNode(c);
        if (!head)
            head = newNode;
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
        }
        temp = newNode;
    }

    cout << (isPalindrome(head) ? "Palindrome" : "Not Palindrome") << endl;
}