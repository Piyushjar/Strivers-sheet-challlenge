#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> res;
vector<vector<int>> grid;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

bool isSafe(int i, int j)
{
    return (i < n && j < n && i >= 0 && j >= 0);
}

void flatten()
{
    vector<int> curr;
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < n; l++)
        {
            curr.push_back(grid[k][l]);
        }
    }
    res.push_back(curr);
}

void solve(vector<vector<int>> &maze, int i, int j)
{
    if (i == n - 1 && j == n - 1)
    {
        grid[i][j] = 1;
        flatten();
        grid[i][j] = 0;
        return;
    }
    maze[i][j] = 0;
    for (auto &d : dir)
    {
        int nr = i + d[0];
        int nc = j + d[1];
        if (isSafe(nr, nc) && maze[nr][nc] == 1)
        {
            grid[nr][nc] = 1;
            solve(maze, nr, nc);
            grid[nr][nc] = 0;
        }
    }
    maze[i][j] = 1;
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int N)
{
    // Write your code here.
    n = N;
    grid.resize(n, vector<int>(n, 0));
    if (maze[0][0] == 0)
        return res;
    grid[0][0] = 1;
    solve(maze, 0, 0);
    return res;
}