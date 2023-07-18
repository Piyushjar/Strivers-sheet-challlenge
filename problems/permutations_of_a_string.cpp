#include <bits/stdc++.h>
using namespace std;

void permute(string &s, int l, int r, vector<string> &res)
{
    if (l == r)
    {
        res.push_back(s);
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(s[l], s[i]);
        permute(s, l + 1, r, res);
        swap(s[l], s[i]);
    }
}
vector<string> findPermutations(string &s)
{
    // Write your code here.
    vector<string> res;
    permute(s, 0, s.length() - 1, res);
    return res;
}