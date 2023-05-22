// InorderTraversal left-current-right

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *createNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    struct node *root = createNode(1);
    struct node *node2 = createNode(2);
    struct node *node3 = createNode(3);
    struct node *node4 = createNode(4);
    struct node *node5 = createNode(5);
    struct node *node6 = createNode(6);
    struct node *node7 = createNode(7);
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node6->left = node7;

    cout << "the In order of BST is : \n";
    printInOrder(root);
    cout << '\n';

    return 0;
}