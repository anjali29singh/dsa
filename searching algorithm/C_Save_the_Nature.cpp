#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, a, b;

        long long k;

        cin >> n;

        long long p[n];

        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        sort(p, p + n, greater<int>());

        cin >> x >> a >> y >> b;
        if (x < y)
        {
            swap(x, y);
            swap(a, b);
        }
        // long long prod = a * b;
        long long c = (1ll * a * b) / __gcd(a, b);
        cin >> k;
        int l = 0, r = n + 1;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            long long ans = 0;
            // number of tickets contributing to (x+y)%,x% and y%
            int cxy = mid / c, cx = (mid / a) - cxy, cy = (mid / b) - cxy;

            for (int i = 0; i < cxy; i++)

                ans = ans + (p[i] / 100) * (x + y);

            for (int i = cxy; i < cxy + cx; i++)

                ans = ans + (p[i] / 100) * x;

            for (int i = cxy + cx; i < cxy + cx + cy; i++)

                ans = ans + (p[i] / 100) * y;

            if (ans >= k)

                r = mid;
            else

                l = mid;
        }
        if (r == (n + 1))
            cout << -1 << endl;
        else
            cout << r << endl;
    }
    return 0;
}