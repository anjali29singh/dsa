#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> adj[N + 1];
    int indegree[N + 1];
    for (int i = 0; i < N; i++)
        indegree[i] = 0;

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v] = indegree[v] + 1;
    }
    queue<int> q;
    vector<int> topo;
    for (int i = 0; i <= N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto v : adj[node])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    for (int i = 0; i <= N; i++)
        cout << topo[i] << " " << endl;

    return 0;
}