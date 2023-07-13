#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &num, vector<int> &res, int idx, int sum)
{
    if (idx == num.size())
    {
        res.push_back(sum);
        return;
    }
    // pick
    solve(num, res, idx + 1, sum + num[idx]);
    // not pick
    solve(num, res, idx + 1, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> res;
    solve(num, res, 0, 0);
    sort(res.begin(), res.end());
    return res;
}