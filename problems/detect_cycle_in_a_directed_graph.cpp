#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &pathVis, int node)
{
    vis[node] = true;
    pathVis[node] = true;

    for (auto neighbor : adj[node])
    {
        if (!vis[neighbor])
        {
            if (dfs(adj, vis, pathVis, neighbor))
                return true;
        }
        else if (pathVis[neighbor])
            return true;
    }
    pathVis[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adj(n + 1);
    for (auto edge : edges)
        adj[edge.first].push_back(edge.second);

    vector<bool> vis(n + 1, false), pathVis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            if (dfs(adj, vis, pathVis, i))
                return true;
    }
    return false;
}