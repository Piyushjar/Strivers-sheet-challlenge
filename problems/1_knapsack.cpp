#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int solve(vector<int> &values, vector<int> &weights, int n, int w)
{
    if (n == 0 || w == 0)
        return 0;

    if (dp[n - 1][w] != -1)
        return dp[n - 1][w];
    // pick
    if (weights[n - 1] <= w)
    {
        int pick = values[n - 1] + solve(values, weights, n - 1, w - weights[n - 1]);
        int notPick = solve(values, weights, n - 1, w);
        return dp[n - 1][w] = max(pick, notPick);
    }
    else
    { // not pick
        return dp[n - 1][w] = solve(values, weights, n - 1, w);
    }
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    memset(dp, -1, sizeof(dp));
    return solve(values, weights, n, w);
}