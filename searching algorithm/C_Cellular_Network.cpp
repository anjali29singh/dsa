#include "bits/stdc++.h"
using namespace std;
#define ll long long

int possible(int ll r, int n, int m, int a[], int b[])
{
    int pa = 0, pb = 0;
    int cnt = 0;
    while (pa < n && pb < m)
    {
        if (abs(a[pa] - b[pb]) <= r)
        {
            cnt = cnt + 1;
            pa = pa + 1;
        }
        else
        {
            pb = pb + 1;
        }
    }
    if (cnt == n)
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    int ll left = -1000000000, right = 10000000000;
    while (left + 1 < right)
    {
        int ll mid = ((left + right) / 2);
        if (possible(mid, n, m, a, b))
            right = mid;
        else
            left = mid;
    }
    cout << right << '\n';
    return 0;
}