#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, vector<int> &curr, vector<vector<int>> &res, int k, int sum, int idx)
{
    if (idx == arr.size())
    {
        if (sum == k)
        {
            res.push_back(curr);
            return;
        }
        return;
    }
    // pick
    curr.push_back(arr[idx]);
    solve(arr, curr, res, k, sum + arr[idx], idx + 1);
    // not pick
    curr.pop_back();
    solve(arr, curr, res, k, sum, idx + 1);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> res;
    vector<int> curr;
    solve(arr, curr, res, k, 0, 0);
    return res;
}