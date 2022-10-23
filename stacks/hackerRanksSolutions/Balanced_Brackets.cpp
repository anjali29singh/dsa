#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        stack<char> st;
        bool balanced = true;
        for (auto i : s)
        {
            if (i == '{')
                st.push('{');
            else if (i == '(')
                st.push('(');
            else if (i == '[')
                st.push('[');
            else
            {
                if (st.empty() || (i == '}' && st.top() != '{'))
                {
                    balanced = false;
                    break;
                }
                else if (st.empty() || (i == ']' && st.top() != '['))
                {
                    balanced = false;
                    break;
                }
                else if (st.empty() || (i == ')' && st.top() != '('))
                {
                    balanced = false;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if (balanced && st.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}