#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &grid, int x, int y)
{
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
        return false;
    return true;
}

int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    // Write your code here.
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }

    pair<int, int> dir[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto p = q.front();
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int nX = p.first + dir[d].first;
                int nY = p.second + dir[d].second;
                if (isSafe(grid, nX, nY))
                {
                    grid[nX][nY] = 2;
                    q.push({nX, nY});
                }
            }
        }
        if (!q.empty())
            time++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return time;
}