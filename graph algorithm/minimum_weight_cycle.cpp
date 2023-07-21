#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair;
#define INF 0x3f3f3f3f
int N, M;
// assuming maximum limit of vertex is 100000
vector<vector<pair<int, int>>> adj(100000);
// remove edge from undirected graph;

void shortestPath(int src)
{
    vector<int> dist(N, INF);
    dist[src] = 0;

    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;

    pq.push(make_pair(0, src));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto i : adj[u])
        {
            int v = i.first, wt = i.second;
            if (dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}
void addEdge(int u, int v, int wt)
{

    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
void removeEdge(int u, int v, int wt)
{
    for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
    {
        if (it->first == v && it->second == wt)
        {
            adj[u].erase(it);
            break; // Exit the loop once the pair is erased
        }
    }
    for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
    {
        if (it->first == u && it->second == wt)
        {
            adj[v].erase(it);
            break; // Exit the loop once the pair is erased
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    // create edge vector for storing all info of edges

    vector<vector<int>> edges;
    for (int i = 0; i < M; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        addEdge(u, v, wt);
        edges.push_back({u, v, wt});
    }

    for (auto i : edges)
    {
        int u = i[0], v = i[1], wt = i[2];
        removeEdge(u, v, wt);
        shortestPath(0);
        addEdge(u, v, wt);
    }

    return 0;
}