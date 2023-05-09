#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
void dfs(vector<long long> adj[], long long vist[], int node, long long &cnt)
{
    vist[node] = 1;
    cnt = cnt + 1;
    for (auto u : adj[node])
    {
        if (vist[u] != 1)
        {
            dfs(adj, vist, u, cnt);
        }
    }
}
int main()
{
    long long n, p;
    cin >> n >> p;
    vector<long long> adj[n];
    for (auto i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long vist[n];
    for (long long i = 0; i < n; i++)
        vist[i] = 0;
    vector<long long> count;
    for (long long i = 0; i < n; i++)
    {
        if (vist[i] != 1)
        {
            long long cnt = 0;
            dfs(adj, vist, i, cnt);
            count.push_back(cnt);
        }
    }
    long long sum = 0, prev = 0;
    long long ans = 0;
    for (auto i = 1; i < count.size(); i++)
    {
        sum = sum + count[i];
    }
    prev = count[0] * sum;
    ans = prev;
    for (auto i = 1; i < count.size(); i++)
    {
        long long curr = ((prev / count[i - 1]) - count[i]) * count[i];
        ans = ans + curr;
        prev = curr;
    }
    cout << ans << endl;

    return 0;
}