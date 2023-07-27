#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> res;
vector<vector<int>> board;

bool isSafe(int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

void flatten()
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v.push_back(board[i][j]);
        }
    }
    res.push_back(v);
}

void place(int col)
{
    if (col == n)
    {
        flatten();
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;
            place(col + 1);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int N)
{
    // Write your code here.
    n = N;
    board.resize(n, vector<int>(n, 0));
    place(0);
    return res;
}