#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    // three pointer approach
    void reverse()
    {

        if (head == nullptr)
            return;

        Node *curr = head, *next = nullptr, *prev = nullptr;

        while (curr != nullptr)
        {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    // using stack

    void reverse()
    {
        Node *temp = head;
        stack<Node *> s;

        while (temp->next != nullptr)
        {
            s.push(temp);
            temp = temp->next;
        }

        head = temp;
        while (!s.empty())
        {
            temp->next = s.top();
            temp = s.top();
            s.pop();
        }
        temp->next = nullptr;
    }

    void print()
    {

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
    ll.push(5);
    ll.push(6);
    ll.print();
    ll.reverse();
    ll.print();
    return 0;
}