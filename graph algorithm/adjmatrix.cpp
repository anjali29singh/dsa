#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M; // n=nodes m = edges
    cin >> N >> M;
    int adj[N + 1][N + 1];
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}