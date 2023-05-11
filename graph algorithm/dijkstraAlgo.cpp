// dijkstra's algorithm using priority queue
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;
void dijkstra(vector<pair<int, int>> adj[], int dist[], int src)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push(make_pair(dist[src], src));
    while (!pq.empty())
    { // first vertex in pair is min dist
        // extract it from pq
        int u = pq.top().second;
        pq.pop();
        for (auto i : adj[u])
        {
            int v = i.first;
            int wt = i.second;
            if (dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
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
        adj[v].push_back(make_pair(u, wt));
    }
    int dist[N + 1];
    
    for (int i = 0; i <= N; i++)
        dist[i] = 1e9 + 10;
    dist[src] = 0;

    dijkstra(adj, dist, src);
    for (int i = 0; i <= N; i++)
        cout << dist[i] << " ";
    cout << endl;
    return 0;
}
