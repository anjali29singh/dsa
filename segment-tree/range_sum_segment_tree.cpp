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

void update(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr)
    {
        T[v] = val;
    }

    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val); // search position in left child;
        else
            update((2 * v) + 1, tm + 1, tr, pos, val);

        T[v] = T[v * 2] + T[(v * 2) + 1];
    }
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
    int l, r, pos, x;

    cout << "enter the query range" << endl;

    cin >> l >> r;

    build(a, 1, 0, n - 1);

    // assuming zero base indexing ;
    int ans = sum(1, 0, n - 1, l, r);

    cout << "sum is : ";
    cout << ans << endl;

    cout << "enter position and value to update:" << endl;

    cin >> pos >> x;

    update(1, 0, n - 1, pos, x);

    int updateSum = sum(1, 0, n - 1, l, r);

    cout << "Sum after update is: ";

    cout << updateSum << '\n';

    return 0;
}