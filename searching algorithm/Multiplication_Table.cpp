#include "bits/stdc++.h"
using namespace std;
#define ll long long

int median(int ll n, int ll k, int ll mid)
{
    int ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int ll columns = mid / i;
        cnt = cnt + min(n, columns);
    }
    if (cnt >= k)
        return 1;
    else
        return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int ll n;
    cin >> n;
    // number of numbers in table less than equal to x is atleast ((n*n)+1)/2
    int ll k = ((n * n) + 1) / 2;
    int ll left = 0, right = n * n;
    while (left + 1 < right)
    {
        int ll mid = (left + right) / 2;
        if (median(n, k, mid))
            right = mid;
        else
            left = mid;
    }
    cout << right << '\n';

    return 0;
}