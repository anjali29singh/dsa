#include <bits/stdc++.h>
using namespace std;

#define maxn 500

int n, St[maxn][maxn];

void buildTable(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        St[i][0] = arr[i];
    }

    // St[i][j] means range (i,(2^j)-1)

    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; (i + (1 << j) - 1) <= n; i++)
        {
            if (St[i][j - 1] < St[i + (1 << (j - 1))][j - 1])
                St[i][j] = St[i][j - 1];
            else
                St[i][j] = St[i + (1 << (j - 1))][j - 1];
        }
    }
}

// query function

int query(int l, int r)
{

    int j = (int)log2(r - l + 1);
    if (St[l][j] <= St[(r - (1 << j)) + 1][j])
        return St[l][j];
    else
        return St[(r - (1 << j)) + 1][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l, r;

    cin >> l >> r;

    buildTable(arr, n);

    int ans = query(l, r);

    cout << ans << '\n';

    return 0;
}