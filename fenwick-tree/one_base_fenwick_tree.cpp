#include <bits/stdc++.h>
using namespace std;

struct fenwickTree
{
    vector<int> T;
    int N;
    fenwickTree(int n)
    {
        this->N = n + 1;
        T.assign(N, 0);
    }
    fenwickTree(vector<int> &arr) : fenwickTree(arr.size())
    {
        for (int i = 0; i < arr.size(); i++)
        {
            update(i, arr[i]);
        }
    }

    void update(int i, int x)
    { //++i for one base indexing
        for (++i; i < N; i = i + (i & (-i)))
        {
            T[i] = T[i] + x;
        }
    }
    // for query till n

    int query(int i)
    {
        // find the parent of i till parent==dummy node
        int ans = 0;
        // if i is 0 base indexing then
        for (++i; i > 0; i = i - (i & (-i)))
        {
            ans = ans + T[i];
        }
        return ans;
    }
    // query between l,r
    // query (r)-query(l-1)
    int query(int l, int r)
    {
        return (query(r) - query(l - 1));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    fenwickTree fec = fenwickTree(arr);
    int sum = fec.query(q);
    cout << sum << '\n';

    return 0;
}