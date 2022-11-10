// dijkstra's algorithm using priority queue
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;
void dijkstra(vector<int> adj[], int dist[], int parent[])
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push(make_pair(dist[1], 1));
    while (!pq.empty())
    { // first vertex in pair is min dist
        // extract it from pq
        int u = pq.top().second;
        pq.pop();
        for (auto v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }
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
    int dist[N + 1]{0};
    int parent[N + 1];
    for (int i = 0; i <= N; i++)
    {
        dist[i] = 1e9 + 10;
        parent[i] = -1;
    }
    dist[1] = 0;

    dijkstra(adj, dist, parent);
    if (dist[N] == 1e9 + 10)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {

        cout << dist[N] + 1 << endl; // no of computers
        vector<int> ans;
        ans.push_back(N);
        int ind = N;
        while (parent[ind] != -1)
        {
            ans.push_back(parent[ind]);
            ind = parent[ind];
        }
        for (int i = dist[N]; i >= 0; i--)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
