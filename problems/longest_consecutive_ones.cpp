#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int count = 0, start = 0, res = 0;
    for (int end = 0; end < n; end++)
    {
        if (arr[end] == 0)
            count++;
        while (count > k)
        {
            if (arr[start] == 0)
                count--;
            start++;
        }
        res = max(end - start + 1, res);
    }
    return res;
}
