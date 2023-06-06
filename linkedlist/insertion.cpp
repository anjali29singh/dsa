#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void pushFront(Node **head, int val)

{
    // creating new node

    Node *new_node = new Node(val);

    // new node will point to previous head node

    new_node->next = *head;

    *head = new_node; // move head to new node
}

void insertAfter(Node *prev_node, int val)
{
    if (prev_node == NULL)
    {
        return;
    }

    // create new node
    Node *new_node = new Node(val);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// append new node at the end
void append(Node **head, int new_val)
{
    // allocate node
    Node *new_node = new Node(new_val);

    Node *last = *head;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
    {

        last = last->next;
    }
    // change the next of last node
    last->next = new_node;
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // make one node which points to head node
    // headPtr contains the points the head node

    Node *head = new Node(1); // head node
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // passing refrence to pointer in pushFront function
    pushFront(&head, 8);

    insertAfter(node3, 6);
    append(&head, 9);
    printList(head);
    cout << '\n';

        return 0;
}