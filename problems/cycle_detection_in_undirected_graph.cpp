#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<int> &vis, int node, int parent)
{
    vis[node] = 1;

    for (auto neighbor : adj[node])
    {
        if (!vis[neighbor])
        {
            if (dfs(adj, vis, neighbor, node))
                return true;
        }
        else if (neighbor != parent)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(adj, vis, i, -1))
                return "Yes";
        }
    }
    return "No";
}
