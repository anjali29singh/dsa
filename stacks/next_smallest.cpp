#include <bits/stdc++.h>
using namespace std;
#include <stack>
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int nextsmallest[n];
    for (int i = 0; i < n; i++)
        nextsmallest[i] = -1;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() >= arr[i])
        {
            s.pop();
        }
        nextsmallest[i] = s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << nextsmallest[i] << " ";
    }
    cout << endl;

    return 0;
}