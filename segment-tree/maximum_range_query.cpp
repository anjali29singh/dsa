// find maximum number in given range
#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e6);
int n, T[maxn];
void build(int arr[], int v, int tl, int tr)
{

    if (tl == tr)
    {
        T[v] = arr[tl];
    }
    else
    {

        int tm = (tl + tr) / 2;

        build(arr, 2 * v, tl, tm);

        build(arr, 2 * v + 1, tm + 1, tr);

        T[v] = max(T[2 * v], T[2 * v + 1]);
    }
}

int find_max(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return T[v];
    else
    {

        int tm = (tl + tr) / 2;
        int left = find_max(2 * v, tl, tm, l, min(r, tm)); // intersection of (l,r) with left child

        int right = find_max(2 * v + 1, tm + 1, tr, max(l, tm + 1), r); // intersection of (l,r) with right child

        return max(left, right);
    }
}

void update(int v, int tl, int tr, int pos, int x)
{

    if (tl == tr)
        T[v] = x;
    else
    {

        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(2 * v, tl, tm, pos, x);
        }

        else
        {
            update(2 * v + 1, tm + 1, tr, pos, x);
        }

        T[v] = max(T[2 * v], T[2 * v + 1]);
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

    int l, r, pos, x;

    cin >> l >> r;

    build(arr, 1, 0, n - 1);

    int ans = find_max(1, 0, n - 1, l, r);

    cout << "maximum number in the range is" << endl;
    cout << ans << '\n';
    cout << "enter position and value to update" << endl;
    cin >> pos >> x;

    update(1, 0, n - 1, pos, x);

    int updateMx = find_max(1, 0, n - 1, l, r);

    cout << "maximum number after update is" << endl;
    cout << updateMx << '\n';
    return 0;
}