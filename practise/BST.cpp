#include <bits/stdc++.h>
using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *right;
//     Node *left;
//     Node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// Node *insertBST(Node *root, int val)
// {
//     if (root == NULL)
//     {
//         return new Node(val);
//     }
//     if (root->data < val)
//     {
//         root->right = insertBST(root->right, val);
//         return root;
//     }
//     root->left = insertBST(root->left, val);
//     return root;
// }

// void inOrder(Node *root)
// {
//     if (root == NULL)
//         return;

//     inOrder(root->left);
//     cout << root->data;
//     inOrder(root->right);
//     return;
// }

// int main()
// {

//     Node *root = insertBST(NULL, 5);
//     Node *p1 = insertBST(root, 3);
//     Node *p2 = insertBST(root, 6);
//     Node *p3 = insertBST(root, 2);
//     Node *p4 = insertBST(root, 1);
//     Node *p5 = insertBST(root, 7);
//     Node *p6 = insertBST(root, 9);

//     inOrder(root);
// }

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
    int height = 1;

    Node(int val)
    {
        data = val;
    }
};

int getHeight(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int balanceFactor(Node *n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Node *createNode(int key)
{
    Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *rotateLeft(Node *node)
{

    Node *x = node->right;
    Node *t = x->left;

    node->right = t;
    x->left = node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}
Node *rotateRight(Node *node)
{

    Node *x = node->left;
    Node *t = x->right;

    node->left = t;
    x->right = node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

/*You are required to complete this method */
Node *insertToAVL(Node *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (node->data < data)
    {
        node->right = insertToAVL(node->right, data);
    }
    else if (data < node->data)
    {
        node->left = insertToAVL(node->left, data);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int bf = balanceFactor(node);

    if (bf > 1 && data < node->left->data)
    {
        // left left
        return rotateRight(node);
    }
    if (bf < -1 && node->right->data < data)
    {
        // right right
        return rotateLeft(node);
    }

    if (bf > 1 && data > node->left->data)
    {
        // left right
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1 && data < node->right->data)
    {
        // right left
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = insertToAVL(NULL, 5);
    Node *p1 = insertToAVL(root, 3);
    Node *p2 = insertToAVL(root, 6);
    Node *p3 = insertToAVL(root, 2);
    Node *p4 = insertToAVL(root, 1);
    Node *p5 = insertToAVL(root, 7);
    Node *p6 = insertToAVL(root, 9);

    inorder(root);
    cout << endl;
    preorder(root);
}