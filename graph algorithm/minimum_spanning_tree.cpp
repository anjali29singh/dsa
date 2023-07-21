// A spanning tree is defined as a tree - like subgraph of a connected,
// undirected graph that includes all the vertices of the grap
// A minimum spanning tree (MST) is defined as a spanning tree that
// has the minimum weight among all the possible spanning trees.

// KRUSKAL'S MINIMUM SPANNIG TREE ALGORITHM

#include <bits/stdc++.h>
using namespace std;
int V, E;
typedef pair<int, int> ipair;
int INF = 1000000;
void primMST(vector<vector<pair<int, int>>> adj)
{

    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;

    int src = 0;

    vector<int> key(V, INF);

    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
        {
            continue;
        }
        inMST[u] = true;

        for (auto i : adj[u])
        {
            int v = i.first, wt = i.second;
            if (!inMST[v] && key[v] > wt)
            {
                key[v] = wt;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        cout << "parent of" << i << " " << parent[i] << '\n';
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V); // assuming 0 base indexing

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    primMST(adj);
    return 0;
}