#include <bits/stdc++.h>
using namespace std;
#include <stack>
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int prevsmallest[n];
    for (int i = 0; i < n; i++)
        prevsmallest[i] = -1;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() >= arr[i])
        {
            s.pop();
        }
        prevsmallest[i] = s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << prevsmallest[i] << " ";
    }
    cout << endl;

    return 0;
}