#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], int visited[], int node)
{
    visited[node] = 1;
    for (auto j : adj[node])
    {
        if (visited[j] != 1)
            dfs(adj, visited, j);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int visited[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        visited[i] = 0;
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(adj, visited, i);

            ans.push_back(i);
            cnt = cnt + 1;
        }
    }
    cout << cnt - 1 << endl;
    for (int i = 0; i < cnt - 1; i++)
        cout << ans[i] << " " << ans[i + 1] << endl;

    return 0;
}