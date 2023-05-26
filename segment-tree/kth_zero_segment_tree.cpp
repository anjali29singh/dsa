// counting the number of zeros in a given range and searching for the kth zero
// store the number of zeroes in T
#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e6);
int n, T[maxn];

void build(int arr[], int v, int tl, int tr)
{
    if (tl == tr && arr[tl] == 0)
    {
        T[v] = 1;
    }
    else if (tl == tr && arr[tl] != 0)
        T[v] = 0;
    else
    {
        int tm = (tl + tr) / 2;

        build(arr, 2 * v, tl, tm);
        build(arr, 2 * v + 1, tm + 1, tr);

        T[v] = T[2 * v] + T[2 * v + 1];
    }
}

int count_zero(int v, int tl, int tr, int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    else if (tl == l && tr == r)
        return T[v];
    else
    {
        int tm = (tl + tr) / 2;
        // part of (l,r) present in left child
        int zero_left = count_zero(2 * v, tl, tm, l, min(tm, r));
        // in right child
        int zero_right = count_zero(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);

        return zero_left + zero_right;
    }
}

void update(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr && val == 0)
    {
        T[v] = 1;
    }
    else if (tl == tr && val != 0)
        T[v] = 0;

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
// kth zero will be present in segment having T[v]>=k
int find_kth(int v, int tl, int tr, int k)
{
    if (k > T[v])
        return -1; // not possible
    else if (tl == tr)
        return tl;

    int tm = (tl + tr) / 2;
    if (T[2 * v] >= k)
        return find_kth(2 * v, tl, tm, k);
    else
        return find_kth(2 * v, tm + 1, tr, k - T[2 * v]);
}
int main()
{
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l, r;
    cout << "enter range for counting zeroes" << endl;

    cin >> l >> r;

    build(arr, 1, 0, n - 1);

    int ans = count_zero(1, 0, n - 1, l, r);
    cout << "number of zeroes present in interval l,r is: " << ans << endl;

    int pos, val;
    cout << "enter position and value for update" << endl;
    cin >> pos >> val;

    update(1, 0, n - 1, pos, val);

    int updateAns = count_zero(1, 0, n - 1, l, r);
    cout << "count of zeroes in given range after updation: " << updateAns << endl;

    return 0;
}