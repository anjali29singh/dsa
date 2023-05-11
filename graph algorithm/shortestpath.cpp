// shortest path in DAG using dfs
#include <bits/stdc++.h>
using namespace std;
void topologicalSort(vector<pair<int, int>> adj[], int visited[], stack<int> &stack, int node)
{
    visited[node] = 1;
    for (auto v : adj[node])
    {
        int u = v.first;
        if (visited[u] == 0)
        {
            topologicalSort(adj, visited, stack, u);
        }
    }
    stack.push(node);
}
int main()
{
    int N, M, src; // source from which shortest distance is to find
    cin >> N >> M >> src;
    vector<pair<int, int>> adj[N + 1];
    for (int i = 0; i < M; i++)
    {

        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
    }
    int visited[N + 1];
    for (int i = 0; i < N + 1; i++)
    {

        visited[i] = 0;
    }
    stack<int> stack;
    int distance[N + 1];
    for (int i = 0; i <= N; i++)
    {
        distance[i] = 10000000;
    }
    for (int i = 0; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            topologicalSort(adj, visited, stack, i);
        }
    }
    distance[src] = 0;
    while (stack.empty() == false)
    {
        int node = stack.top();
        int dist = distance[node]; // minimum distance to reach node
        stack.pop();
        for (auto u : adj[node])
        {
            int v = u.first;
            int wt = u.second;
            distance[v] = min(distance[v], dist + wt);
        }
    }
    for (int i = 0; i <= N; i++)
    {
        if (distance[i] == 10000000)
            cout << "sorry we can't reach here " << endl;
        else
            cout << distance[i] << " " << endl;
    }
    return 0;
}