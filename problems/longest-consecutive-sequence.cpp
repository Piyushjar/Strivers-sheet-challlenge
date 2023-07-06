#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    int res = 1;
    unordered_set<int> s;
    for (int i : arr)
        s.insert(i);

    for (int it : s)
    {
        if (s.find(it - 1) == s.end())
        {
            int count = 1;
            int t = it;
            while (s.find(t + 1) != s.end())
            {
                t = t + 1;
                count = count + 1;
            }
            res = max(res, count);
        }
    }
    return res;
}