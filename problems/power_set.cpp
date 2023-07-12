#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &v, int idx, vector<vector<int>> &res, vector<int> curr)
{
    if (idx == v.size())
    {
        res.push_back(curr);
        return;
    }
    // pick
    curr.push_back(v[idx]);
    solve(v, idx + 1, res, curr);
    // not pick
    curr.pop_back();
    solve(v, idx + 1, res, curr);
}

vector<vector<int>> pwset(vector<int> v)
{
    vector<vector<int>> res;
    solve(v, 0, res, {});
    return res;
}