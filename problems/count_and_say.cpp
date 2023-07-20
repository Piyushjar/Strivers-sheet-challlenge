#include <bits/stdc++.h>
using namespace std;

string say(string s)
{
    int count = 1;
    string res = "";
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i - 1] != s[i])
        {
            res += to_string(count);
            res += s[i - 1];
            count = 1;
        }
        else
            count++;
    }
    res += to_string(count);
    res += s[s.length() - 1];
    return res;
}