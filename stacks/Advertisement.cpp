#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    vector<int> prev(n, -1);

    vector<int> next(n, n);

    stack<int> st;

    st.push(0);

    for (int i = 1; i < n; i++)
    {

        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
            prev[i] = st.top();
        st.push(i);
    }

    st = stack<int>();

    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--)
    {

        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
            next[i] = st.top();
        st.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long wt = abs(prev[i] - next[i]) - 1;
        long long ht = arr[i];

        ans = max(ans, wt * ht);
    }
    cout << ans << endl;

    return 0;
}