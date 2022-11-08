#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

void dfs(vector<int> adj[], int vis[], int node, int &city)
{
    city = city + 1;
    vis[node] = 1;
    for (auto u : adj[node])
    {
        if (!vis[u])
        {
            dfs(adj, vis, u, city);
        }
    }
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, m, cl, cr;
        cin >> n >> m >> cl >> cr;

        vector<int> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int c1, c2;
            cin >> c1 >> c2;
            adj[c1].push_back(c2);
            adj[c2].push_back(c1);
        }
        int vis[n + 1] = {0};
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                int city = 0; // cities in connected components
                dfs(adj, vis, i, city);
                if (cl < cr)
                    ans = ans + (city * cl);
                else
                    ans = ans + ((city - 1) * cr) + cl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
