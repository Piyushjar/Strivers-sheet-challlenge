#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctElements(vector<int> &arr, int k)
{
    // Write your code here
    vector<int> res;
    unordered_map<int, int> m;
    for (int i = 0; i < k; i++)
    {
        m[arr[i]]++;
    }
    res.push_back(m.size());
    for (int i = k; i < arr.size(); i++)
    {
        m[arr[i]]++;
        m[arr[i - k]]--;
        if (m[arr[i - k]] == 0)
            m.erase(arr[i - k]);
        res.push_back(m.size());
    }
    return res;
}
