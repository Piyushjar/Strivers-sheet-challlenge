#include <bits/stdc++.h>
using namespace std;

void dfs(int **arr, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    if (arr[i][j] == 0)
        return;

    arr[i][j] = 0;

    // four directions
    dfs(arr, i + 1, j, n, m);
    dfs(arr, i - 1, j, n, m);
    dfs(arr, i, j + 1, n, m);
    dfs(arr, i, j - 1, n, m);
    // diagonals
    dfs(arr, i - 1, j - 1, n, m);
    dfs(arr, i + 1, j + 1, n, m);
    dfs(arr, i + 1, j - 1, n, m);
    dfs(arr, i - 1, j + 1, n, m);
}

int getTotalIslands(int **arr, int n, int m)
{
    // Write your code here.
    int islands = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                dfs(arr, i, j, n, m);
                islands++;
            }
        }
    }
    return islands;
}
