#include "bits/stdc++.h"
using namespace std;
#define ll long long

int subarray(int ll a[], int n, int k, int ll mid)
{
    int cnt = 1;
    int ll currentsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentsum + a[i] <= mid)
        {
            currentsum = currentsum + a[i];
        }
        else if (a[i] == mid)
        {
            currentsum = 0;
            cnt = cnt + 1;
        }
        else
        {
            currentsum = a[i];
            cnt = cnt + 1;
        }
    }
    if (cnt <= k)
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int long long n, k;
    cin >> n >> k;
    int ll a[n];
    int ll l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        r = r + a[i];
        l = max(l, a[i]);
    }
    l = l - 1;
    while (l + 1 < r)
    {
        int ll mid = (l + r) / 2;
        if (subarray(a, n, k, mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';

    return 0;
}