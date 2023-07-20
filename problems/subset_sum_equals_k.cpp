#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr, int k, int idx, int sum, vector<vector<int>> &dp)
{
    if (idx == arr.size())
    {
        if (sum == k)
            return true;
        return false;
    }
    if (sum > k)
        return false;
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
    // pick
    bool include = solve(arr, k, idx + 1, sum + arr[idx], dp);
    // not pick
    bool exclude = solve(arr, k, idx + 1, sum, dp);

    return dp[idx][sum] = (include || exclude);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(arr, k, 0, 0, dp);
}