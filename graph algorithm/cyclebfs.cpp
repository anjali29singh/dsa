// detech cycle in undirected graph using bfs
#include <bits/stdc++.h>
using namespace std;

bool detect_cycle(vector<int> adj[], int visited[], int v)
{
    visited[v] = 1;
    queue<pair<int, int>> q;
    q.push({v, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        for (auto u : adj[node])
        {
            if (!visited[u])
            {
                visited[u] = 1;
                q.push({u, node});
            }
            else if (u != parent)
                return true;
        }
    }
    return false;
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
    bool ispresent = false;
    // assume 1 base indexing
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (detect_cycle(adj, visited, i))
            {
                ispresent = true;
                break;
            }
        }
    }
    if (ispresent)
        cout << "yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}