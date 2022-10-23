#include <bits/stdc++.h>
#include <stack>
using namespace std;
// next greatest element to the right of x
int main()
{
    int n;
    cin >> n;
    int arr[n];
    stack<int> stk;
    int nextGreatest[n];
    for (int i = 0; i < n; i++)
        nextGreatest[i] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stk.push(1000000); // very big no. at the bottom
    for (int i = n - 1; i >= 0; i--)
    {
        while (stk.top() <= arr[i])
        {
            stk.pop();
        }
        nextGreatest[i] = stk.top();
        stk.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (nextGreatest[i] == 1000000)
            cout << -1 << " ";
        else
            cout << nextGreatest[i] << " ";
    }
    cout << endl;

    return 0;
}