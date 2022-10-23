// infix: The exp of form a op b .eg 1+2
// postfix:The exp of form ab op.eg 1 2+
#include <bits/stdc++.h>
#include <stack>
using namespace std;
#include <string>
int prece(char s)
{
    if (s == '+' || s == '-')
        return 1;
    else if (s == '^')
        return 3;
    else
        return 2;
}
int main()
{
    string str, result = "";
    cin >> str;
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            result = result + c;
        }
        else if (c == '(')
            st.push('(');
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result = result + st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prece(c) <= prece(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    cout << result << endl;
    return 0;
}
