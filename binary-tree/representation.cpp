#include <bits/stdc++.h>
using namespace std;
// method 1 using struct
struct node
{
    int data;
    node *left;
    node *right;

    // create new node
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// method 2 using class
// class Node
// {
//     int data;
//     Node *left;
//     Node *right;
// };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    node *root = new node(1);
    node *node2 = new node(2);
    node *node3 = new node(3);
    node *node4 = new node(4);
    node *node5 = new node(5);

    // constructing tree
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;

    return 0;
}