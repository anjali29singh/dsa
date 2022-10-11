#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], int visited[], int node)
{
    visited[node] = 1;
    for (auto j : adj[node])
    {
        if (visited[node] != 1)
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
    int visited[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(adj, visited, i);
        }
    }

    return 0;
}