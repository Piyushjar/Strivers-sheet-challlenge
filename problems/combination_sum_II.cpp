#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n, int idx, int target, int sum, vector<int> curr, set<vector<int>> &st)
{
    if (target == sum)
    {
        st.insert(curr);
        return;
    }
    if ((idx == n) || (sum > target))
        return;
    // pick
    curr.push_back(arr[idx]);
    solve(arr, n, idx + 1, target, sum + arr[idx], curr, st);
    // not pick
    curr.pop_back();
    while (idx + 1 < n && arr[idx] == arr[idx + 1])
        idx++;
    solve(arr, n, idx + 1, target, sum, curr, st);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    set<vector<int>> st;
    solve(arr, n, 0, target, 0, {}, st);
    for (auto it : st)
    {
        res.push_back(it);
    }
    return res;
}
