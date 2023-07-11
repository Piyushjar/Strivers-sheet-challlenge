#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{
    int n = arr.size();
    unordered_map<int, int> m;
    int preSum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (preSum == 0)
            res = i + 1;
        else
        {
            if (m.find(preSum) != m.end())
            {
                res = max(res, i - m[preSum]);
            }
            else
                m[preSum] = i;
        }
    }
    return res;
}