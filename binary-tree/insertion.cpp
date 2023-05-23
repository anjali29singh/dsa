// traverse tree in level order
// find node whose left child is empty or else who right child is empty then insert node at the side

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node *insertNode(node *root, int data)
{ // if empty tree assign new node address to root
    if (root == NULL)
    {
        root = new node(data);
    }

    // else do level order traversal until a left or right child is find empty;

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct node *Node = q.front();
        q.pop();
        if (Node->left != NULL)
        {
            q.push(Node->left);
        }
        else
        {
            struct node *newNode = new node(data);
            Node->left = newNode;

            return root;
        }
        if (Node->right != NULL)
        {
            q.push(Node);
        }
        else
        {
            struct node *newNode = new node(data);
            Node->right = newNode;
            return root;
        }
    }
    return root;
}

void printInOrder(struct node *Node)
{
    if (Node == NULL)
    {

        return;
    }
    // recurr left child
    printInOrder(Node->left);

    cout << Node->data << " ";
    // recurr right child;
    printInOrder(Node->right);
}

int main()
{
    struct node *root = new node(1);
    struct node *node2 = new node(2);
    struct node *node3 = new node(3);
    struct node *node4 = new node(4);
    struct node *node5 = new node(5);
    struct node *node6 = new node(6);
    struct node *node7 = new node(7);
    struct node *node8 = new node(8);
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node4->left = node8;

    printInOrder(root);
    cout << endl;
    root = insertNode(root, 10);
    printInOrder(root);
    cout << endl;

    return 0;
}