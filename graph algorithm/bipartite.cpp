#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[], int color[], int node, int col)
{
    color[node] = col;
    for (auto adjacent_node : adj[node])
    {
        if (color[adjacent_node] == -1)
        {

            if (dfs(adj, color, adjacent_node, !col) == false)
                return false;
        }
        else if (color[adjacent_node] == col)
            return false;
    }
    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> adj[N + 1];
    for (int i = 0; i < M; i++)
    {

        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int color[N + 1];
    for (int i = 0; i < N + 1; i++)
    {
        color[i] = -1;
    }
    for (int i = 1; i <= N; i++)
        color[i] = -1;
    bool bipartite = true;
    for (int i = 1; i <= N; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(adj, color, i, 0) == false)
            {
                bipartite = false;
                break;
            }
        }
    }
    if (bipartite)
        cout << "Yes graph is bipartite" << endl;
    else
        cout << "NO" << endl;

    return 0;
}