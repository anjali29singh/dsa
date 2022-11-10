// In this question check the bipartiteness of graph
#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[], int team[], int node, int team_no)
{
    team[node] = team_no;
    for (auto adjacent_node : adj[node])
    {
        if (team[adjacent_node] == -1)
        {

            if (dfs(adj, team, adjacent_node, !team_no) == false)
                return false;
        }
        else if (team[adjacent_node] == team_no)
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
    int team[N + 1] = {-1};
    for (int i = 1; i <= N; i++)
        team[i] = -1;
    bool bipartite = true;
    for (int i = 1; i <= N; i++)
    {
        if (team[i] == -1)
        {
            if (dfs(adj, team, i, 0) == false)
            {
                bipartite = false;
                break;
            }
        }
    }
    if (bipartite)
    {
        for (int i = 1; i <= N; i++)
        {
            if (team[i] == 0)
                cout << 1 << " ";
            else
                cout << 2 << " ";
        }
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}