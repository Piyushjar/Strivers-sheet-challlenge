#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int node, vector<bool> &vis, vector<int> &curr)
{
    vis[node] = true;
    curr.push_back(node);

    for (auto u : adj[node])
    {
        if (!vis[u])
            dfs(adj, u, vis, curr);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adj(V + 1);
    for (int i = 0; i < E; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> vis(V, false);
    vector<vector<int>> res;
    for (int i = 0; i < V; i++)
    {
        vector<int> v;
        if (!vis[i])
        {
            dfs(adj, i, vis, v);
            res.push_back(v);
        }
    }
    return res;
}