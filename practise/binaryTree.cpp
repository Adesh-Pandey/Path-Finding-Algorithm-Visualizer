#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data;

    preOrder(root->left);
    preOrder(root->right);
}

int search(int arr[], int item, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (item == arr[i])
            cout << item;
        return i;
    }
    return -1;
}

Node *Build(int preorderr[], int inorder[], int start, int end)
{

    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorderr[idx];
    idx++;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, curr, start, end);

    node->left = Build(preorderr, inorder, start, pos - 1);
    node->right = Build(preorderr, inorder, pos + 1, end);
    return node;
}

int main()
{
    int preorderr[] = {1, 2, 3, 4, 5, 6, 7};
    int inorder[] = {3, 2, 4, 1, 6, 5, 7};
    Node *root = Build(preorderr, inorder, 0, 6);
    cout << root->data << endl;

    preOrder(root);
}