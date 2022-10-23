#include <bits/stdc++.h>
using namespace std;
#include <stack>

int find_max(stack<int> st)
{
    int max_num = 0;
    while (!st.empty())
    {
        max_num = max(max_num, st.top());
        st.pop();
    }
    return max_num;
}
int main()
{
    int N;
    cin >> N;
    stack<int> st;
    int mxnum = 0;
    for (int i = 0; i < N; i++)
    {
        int q, x;
        cin >> q;
        if (q == 1)
        {
            cin >> x;
            mxnum = max(mxnum, x);
            st.push(x);
        }
        else if (q == 2)
        {
            if (st.top() == mxnum)
            {
                st.pop();
                mxnum = find_max(st);
            }
            else
                st.pop();
        }
        else
            cout << mxnum << endl;
    }

    return 0;
}
