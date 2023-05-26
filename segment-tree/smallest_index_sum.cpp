// for given value of x find the smallest i for which sum>=x

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

int smallest_ind(int v, int tl, int tr, int sum)
{
    if (T[v] < sum)
        return -1; // not possible
    else if (tl == tr && T[v] >= sum)
        return tl;
    else
    {

        int tm = (tl + tr) / 2;
        if (T[2 * v] >= sum)
            smallest_ind(2 * v, tl, tm, sum);
        else
            smallest_ind(2 * v + 1, tm + 1, tr, sum - T[2 * v]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int x;

    cin >> x;

    build(arr, 1, 0, n - 1);

    int i = smallest_ind(1, 0, n - 1, x);

    cout << i << '\n';

    return 0;
}