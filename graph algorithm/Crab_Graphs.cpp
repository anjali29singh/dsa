#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, t, m;
        cin >> n >> t >> m;
        vector<int> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (adj[i].size() <= t)
                cnt = cnt + 1;
        }
        cout << cnt << endl;
    }

    return 0;
}