#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    int n = nums.size();
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++)
        pq.push({nums[i], i});
    vector<int> res;
    res.push_back(pq.top().first);
    for (int i = k; i < n; i++)
    {
        pq.push({nums[i], i});
        while (pq.top().second <= i - k)
            pq.pop();
        res.push_back(pq.top().first);
    }
    return res;
}