#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, x;
    cin >> n >> x;
    int long long wt[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    sort(wt, wt + n);
    int ans = 0, l = 0, r = n - 1;
    while (l < r)
    {
        if ((wt[l] + wt[r]) <= x)
        {
            ans = ans + 1;
            l = l + 1;
            r = r - 1;
        }
        else
        {
            ans = ans + 1;
            r = r - 1;
        }
    }
    if (l == r)
        ans = ans + 1;
    cout << ans << endl;
    return 0;
}