#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, vector<vector<int>> &s, vector<int> &curr, int idx)
{
    if (idx == arr.size())
    {
        s.push_back(curr);
        return;
    }
    // pick
    curr.push_back(arr[idx]);
    solve(arr, s, curr, idx + 1);
    // not pick
    curr.pop_back();
    while (idx + 1 < arr.size() && arr[idx] == arr[idx + 1])
        idx++;
    solve(arr, s, curr, idx + 1);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> res;
    vector<int> curr;
    sort(arr.begin(), arr.end());
    solve(arr, res, curr, 0);
    sort(res.begin(), res.end());
    return res;
}