#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{
    int n1, n2, n3, sum1 = 0, sum2 = 0, sum3 = 0;
    cin >> n1 >> n2 >> n3;
    int h1[n1], h2[n2], h3[n3];
    stack<int> s1, s2, s3;
    for (int i = 0; i < n1; i++)
    {
        cin >> h1[i];
        sum1 = sum1 + h1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> h2[i];
        sum2 = sum2 + h2[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> h3[i];
        sum3 = sum3 + h3[i];
    }
    for (int i = n1 - 1; i >= 0; i--)
        s1.push(h1[i]);
    for (int i = n2 - 1; i >= 0; i--)
        s2.push(h2[i]);
    for (int i = n3 - 1; i >= 0; i--)
        s3.push(h3[i]);
    int max_height = 0;
    while (!s1.empty() && !s2.empty() && !s3.empty())
    {
        if (sum1 == sum2 && sum2 == sum3)
        {
            max_height = sum1;
            break;
        }
        if (sum1 > min(sum2, sum3))
        {
            sum1 = sum1 - s1.top();
            s1.pop();
        }
        if (sum2 > min(sum1, sum3))
        {
            sum2 = sum2 - s2.top();
            s2.top();
        }
        if (sum3 >= min(sum1, sum2))
        {
            sum3 = sum3 - s3.top();
            s3.pop();
        }
    }
    cout << max_height << endl;

    return 0;
}
