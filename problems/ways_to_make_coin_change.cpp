#include <bits/stdc++.h>
using namespace std;

long dp[101][100001];

long solve(int *d, int n, int value)
{
    if (value == 0)
        return 1;
    if (n == 0 || value < 0)
        return 0;
    if (dp[n][value] != -1)
        return dp[n][value];
    if (d[n - 1] <= value)
    {
        return dp[n][value] = solve(d, n, value - d[n - 1]) + solve(d, n - 1, value);
    }
    else
        return dp[n][value] = solve(d, n - 1, value);
}

long countWaysToMakeChange(int *d, int n, int value)
{
    // Write your code here
    memset(dp, -1, sizeof(dp));
    return solve(d, n, value);
}