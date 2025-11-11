#include <iostream>
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

// Recursive Search
Node *searchRec(Node *root, int key)
{
    if (!root || root->data == key)
        return root;
    if (key < root->data)
        return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// Non-Recursive Search
Node *searchIter(Node *root, int key)
{
    while (root != nullptr)
    {
        if (key == root->data)
            return root;
        root = (key < root->data) ? root->left : root->right;
    }
    return nullptr;
}

// Minimum Element
Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// Maximum Element
Node *findMax(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

// Inorder Successor
Node *inorderSuccessor(Node *root, Node *target)
{
    if (target->right)
        return findMin(target->right);

    Node *succ = nullptr;
    while (root)
    {
        if (target->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (target->data > root->data)
            root = root->right;
        else
            break;
    }
    return succ;
}

// Inorder Predecessor
Node *inorderPredecessor(Node *root, Node *target)
{
    if (target->left)
        return findMax(target->left);

    Node *pred = nullptr;
    while (root)
    {
        if (target->data > root->data)
        {
            pred = root;
            root = root->right;
        }
        else if (target->data < root->data)
            root = root->left;
        else
            break;
    }
    return pred;
}