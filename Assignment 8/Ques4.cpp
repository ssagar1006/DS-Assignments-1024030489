#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool isBSTUtil(Node *root, int minVal, int maxVal)
{
    if (!root)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    cout << (isBST(root) ? "Valid BST" : "Not a BST") << endl;
}