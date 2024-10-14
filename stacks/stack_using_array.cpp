#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int capacity;
    int *arr;
    int top;

public:
    Stack(int n)
    {

        arr = new int[n];
        top = -1;
        capacity = n;
    }

    void push(int x)
    {

        if (top >= capacity)
            return;
        arr[top + 1] = x;
        top++;
    }

    int peek()
    {

        if (top == -1)
            return -1;
        int val = arr[top + 1];
        top--;
        return val;
    }
};
int main()
{

    return 0;
}