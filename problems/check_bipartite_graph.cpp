#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<int> &color, int node, int col)
{
    color[node] = col;
    for (int nbr : adj[node])
    {
        if (color[nbr] == -1)
        {
            if (!dfs(adj, color, nbr, !col))
                return false;
        }
        else if (color[nbr] == col)
            return false;
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int n = edges.size();
    int m = edges[0].size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
            if (!dfs(adj, color, i, 0))
                return false;
    }
    return true;
}