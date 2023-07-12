#include <bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string input)
{
    int n = input.length();
    unordered_map<char, int> m;
    int res = 0, start = 0, end = 0;
    while (end < n)
    {
        m[input[end]]++;
        if (m.size() == end - start + 1)
        {
            res = max(res, end - start + 1);
        }
        else if (m.size() < end - start + 1)
        {
            while (m.size() < end - start + 1)
            {
                m[input[start]]--;
                if (m[input[start]] == 0)
                    m.erase(input[start]);
                start++;
            }
        }
        end++;
    }
    return res;
}