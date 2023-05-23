// height of empty tree is 0
// time complexity O(n)
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

int height(struct node *Node)
{
    if (Node == NULL)
        return 0;
    else
    {

        int lht = height(Node->left);
        int rht = height(Node->right);
        return max(lht, rht) + 1;
    }
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

    cout << height(root) << endl;

    return 0;
}