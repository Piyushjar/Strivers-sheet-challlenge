#include <bits/stdc++.h>
using namespace std;

bool myComp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> m;
    for (int i : arr)
        m[i]++;

    vector<pair<int, int>> v;
    for (auto it : m)
        v.push_back({it.second, it.first});

    sort(v.begin(), v.end(), myComp);

    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(v[i].second);
    }
    return res;
}