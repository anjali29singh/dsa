#include "bits/stdc++.h"
using namespace std;
#define ll long long
long long int_max = 2e18 + 5;
int reachable(string s, ll x1, ll y1, ll x2, ll y2, ll n, ll k)
{
    // let alone wind move the boat to reach a certain point say x3,y3 in k days
    ll x3 = x1, y3 = y1;
    ll cycle = k / n;
    if (k >= n)
    {
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == 'U')
                y3 = y3 + cycle;
            else if (s[i] == 'D')
                y3 = y3 - cycle;
            else if (s[i] == 'L')
                x3 = x3 - cycle;
            else
                x3 = x3 + cycle;
        }
    }
    for (ll i = 0; i < (k % n); i++)
    {
        if (s[i] == 'U')
            y3 = y3 + 1;
        else if (s[i] == 'D')
            y3 = y3 - 1;
        else if (s[i] == 'L')
            x3 = x3 - 1;
        else
            x3 = x3 + 1;
    }
    return (abs(x2 - x3) + abs(y2 - y3) <= k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    // the effect of separation and instruction +wind is same
    // instruction and wind effect is independent of each other
    ll left = -1, right = int_max;
    while (left + 1 < right)
    {

        ll mid = (left + right) / 2;
        if (reachable(s, x1, y1, x2, y2, n, mid))
            right = mid;
        else
            left = mid;
    }
    cout << (left < int_max / 2 ? right : -1) << '\n';
    return 0;
}