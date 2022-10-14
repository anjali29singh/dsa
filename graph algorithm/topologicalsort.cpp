#include <bits/stdc++.h>
using namespace std;
void topologicalSort(vector<int> adj[], int visited[], stack<int> &stack, int node)
{
    visited[node] = 1;
    for (auto v : adj[node])
    {
        if (visited[v] == 0)
        {
            topologicalSort(adj, visited, stack, v);
        }
    }
    stack.push(node);
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
    }
    int visited[N + 1] = {0};
    stack<int> stack;
    for (int i = 0; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            topologicalSort(adj, visited, stack, i);
        }
    }
    while (stack.empty() == false)
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    return 0;
}