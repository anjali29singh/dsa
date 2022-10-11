#include <bits/stdc++.h>
using namespace std;
bool isCycle(vector<int> adj[], int visited[], int node, int parent)
{
    visited[node] = 1;

    for (auto v : adj[node])
    {
        if (!visited[v])
            isCycle(adj, visited, v, node);
        else if (v != parent)
            return true;
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
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (isCycle(adj, visited, i, -1))
            {
                ispresent = true;
                break;
            }
        }
    }
    if (ispresent)
        cout << "Yes cycle is present" << endl;
    else
        cout << "No" << endl;

    return 0;
}