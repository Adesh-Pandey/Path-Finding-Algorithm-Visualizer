#include <iostream>
using namespace std;
#include <queue>

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

void levelSeries(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> line;

    line.push(root);
    line.push(NULL);

    while (!line.empty())
    {
        Node *node = line.front();

        line.pop();

        if (node != NULL)
        {
            cout << node->data;
            if (node->left)
            {
                line.push(node->left);
            }
            if (node->right)
            {
                line.push(node->right);
            }
        }
        else if (!line.empty())
        {
            line.push(NULL);
        }
    }
}

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return (1 + countNodes(root->left) + countNodes(root->right));
}

int totalSum(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    return (root->data + totalSum(root->left) + totalSum(root->right));
}

int main()
{
    Node *node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    node->right->left = new Node(6);
    node->right->right = new Node(7);

    // levelSeries(node);

    cout << countNodes(node) << endl
         << totalSum(node);
}
