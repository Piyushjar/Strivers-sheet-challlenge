#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int node, stack<int> &st)
{
    vis[node] = true;
    for (auto neighbor : adj[node])
    {
        if (!vis[neighbor])
            dfs(adj, vis, neighbor, st);
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<bool> vis(v, false);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(adj, vis, i, st);
    }
    vector<int> res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}