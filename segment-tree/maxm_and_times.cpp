// find the maximum number in give range and how many times it appears
#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e6);
int n;
pair<int, int> T[maxn];

pair<int, int> combine(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        return a;
    if (b.first > a.first)
        return b;
    // if both equal then add occurences
    return make_pair(a.first, a.second + b.second);
}
void build(int arr[], int v, int tl, int tr)
{
    if (tl == tr)
    {
        T[v] = make_pair(arr[tl], 1);
    }
    else
    {

        int tm = (tl + tr) / 2;
        build(arr, 2 * v, tl, tm);
        build(arr, 2 * v + 1, tm + 1, tr);
        T[v] = combine(T[2 * v], T[2 * v + 1]);
    }
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r)
{

    if (l > r)
        return make_pair(-int(1e6), 0);
    else if (tl == l && tr == r)
    {
        return T[v];
    }
    else
    {
        int tm = (tl + tr) / 2;

        pair<int, int> leftmax = get_max(2 * v, tl, tm, tl, min(tm, r));
        pair<int, int> rightmax = get_max(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(leftmax, rightmax);
    }
}

void update(int v, int tl, int tr, int pos, int val)
{

    if (tl == tr)
    {
        T[v] = make_pair(val, 1);
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            update(2 * v, tl, tm, pos, val);
        }
        else
        {
            update(2 * v + 1, tm + 1, tr, pos, val);
        }
        T[v] = combine(T[2 * v], T[2 * v + 1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    cout << "enter the query range" << endl;
    int l, r;
    cin >> l >> r;
    build(arr, 1, 0, n - 1);

    pair<int, int> ans = get_max(1, 0, n - 1, l, r);
    cout << "maximum number in given range is: " << ans.first << "\nand number of times it appears is: " << ans.second << '\n';

    return 0;
}