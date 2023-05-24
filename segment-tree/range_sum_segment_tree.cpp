#include <bits/stdc++.h>
using namespace std;

const int maxn = int(1e6);
int n, T[4 * maxn];

// create segment tree

void build(int a[], int v, int tl, int tr)
{
    if (tl == tr)
        T[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        // left child
        build(a, 2 * v, tl, tm);
        // right child;
        build(a, (2 * v) + 1, tm + 1, tr);

        T[v] = T[v * 2] + T[(v * 2) + 1];
    }
}

// query for sum in range (l,r)

int sum(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    else if (l == tl && r == tr)
    {
        return T[v];
    }
    int tm = (tl + tr) / 2;

    int leftPartial = sum(v * 2, tl, tm, l, min(tm, r)); // partial sum in left child

    int rightPartial = sum((v * 2) + 1, tm + 1, tr, max(l, tm + 1), r);
    return leftPartial + rightPartial;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l, r;
    cin >> l >> r;
    build(a, 1, 0, n - 1);
    // assuming zero base indexing ;
    int ans = sum(1, 0, n - 1, l, r);

    cout << ans << '\n';
    for (int i = 0; i < 4 * n; i++)
        cout << T[i] << " ";
    cout << '\n';
    return 0;
}