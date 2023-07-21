#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<bool> &vis, int node, vector<int> &res)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    res.push_back(node);
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        for (auto u : adj[p])
        {
            if (!vis[u])
            {
                vis[u] = true;
                res.push_back(u);
                q.push(u);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<bool> vis(vertex, false);
    vector<vector<int>> adj(vertex + 1);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    vector<int> res;
    for (int i = 0; i < vertex; i++)
    {
        sort(adj[i].begin(), adj[i].end());
        if (!vis[i])
            bfs(adj, vis, i, res);
    }
    return res;
}