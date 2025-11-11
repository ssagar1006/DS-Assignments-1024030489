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

// Insert (No Duplicates)
Node *insert(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        cout << "Duplicate not allowed!\n";
    return root;
}

// Delete Node
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node found
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = root->right;
        while (temp->left)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Depth (Height) of BST
int maxDepth(Node *root)
{
    if (!root)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;
    int choice, val;

    while (true)
    {
        cout << "\n--- BST Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Inorder\n4. Max Depth\n5. Min Depth\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            root = insert(root, val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            root = deleteNode(root, val);
            break;
        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Max Depth: " << maxDepth(root) << endl;
            break;
        case 5:
            cout << "Min Depth: " << minDepth(root) << endl;
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid!\n";
        }
    }
}