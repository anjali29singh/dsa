#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n + 1];
        int vis[n + 1];
        for (int i = 0; i < n + 1; i++)
            vis[i] = 0;

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int s; // starting point
        cin >> s;
        queue<pair<int, int>> q;
        int shortdist[n + 1];
        vis[s] = 1;
        for (int i = 0; i <= n; i++)
            shortdist[i] = -1;
        q.push(make_pair(s, 0));
        while (!q.empty())
        {
            int node = q.front().first;
            int dist = q.front().second; // distance to reach parent node
            q.pop();
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    shortdist[it] = 1 + dist;
                    q.push(make_pair(it, shortdist[it]));
                }
                else
                {
                    if (shortdist[it] > (1 + dist))
                    {
                        q.push(make_pair(it, 1 + dist));
                    }

                    shortdist[it] = min(shortdist[it], 1 + dist);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (i != s & shortdist[i] != -1)
                cout << 6 * shortdist[i] << " ";
            else if (i != s)
                cout << shortdist[i] << " ";
        }
        cout << endl;
    }
    return 0;
}