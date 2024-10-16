#include <bits/stdc++.h>
using namespace std;

class Disjoint
{

public:
    vector<int> parent, rank, sizes;
    Disjoint(int n)
    {

        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        sizes.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {

        if (parent[node] == node)
            return parent[node];

        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {

        int ulpu = findUParent(u);
        int ulpv = findUParent(v);

        if (ulpu == ulpv)
        {

            return;
        }

        else if (rank[ulpu] < rank[ulpv])
        {

            parent[ulpu] = ulpv;
        }
        else if (rank[ulpu] > rank[ulpv])
        {

            parent[ulpv] = ulpu;
        }
        else
        {

            parent[ulpu] = ulpv;
            rank[ulpv]++;
        }
    }

    void unionBySize(int u, int v)
    {

        int ulpu = findUParent(u);
        int ulpv = findUParent(v);

        if (ulpu == ulpv)
            return;

        if (sizes[ulpu] > sizes[ulpv])
        {

            parent[ulpv] = ulpu;
            sizes[ulpu] += sizes[ulpv];
        }
        else
        {
            parent[ulpu] = ulpv;
            sizes[ulpv] += sizes[ulpu];
        }
    }
};

class Solution
{

public:
    void solve(vector<vector<int>> edges, int n, int m)
    {

        vector<int> adj[n + 1];

        int numConnectedComponents = n;
        int maxSizeOfComp = 1;

        Disjoint dsu(n);
        for (auto i : edges)
        {

            int u = i[0], v = i[1];

            int ulpu = dsu.findUParent(u), ulpv = dsu.findUParent(v);
            if (ulpu != ulpv)
            {

                dsu.unionBySize(u, v);
                numConnectedComponents--;

                maxSizeOfComp = max(maxSizeOfComp, max(dsu.sizes[ulpu], dsu.sizes[ulpv]));

                cout << numConnectedComponents << " " << maxSizeOfComp << '\n';
            }

            else
            {

                cout << numConnectedComponents << " " << maxSizeOfComp << '\n';
            }
        }
    }
};
int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution s;
    s.solve(edges, n, m);
    return 0;
}