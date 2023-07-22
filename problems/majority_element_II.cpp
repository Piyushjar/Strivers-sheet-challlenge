#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    unordered_map<int, int> m;
    for (int i : arr)
    {
        m[i]++;
    }
    vector<int> res;
    for (auto it : m)
    {
        if (it.second > n / 3)
            res.push_back(it.first);
    }
    return res;
}