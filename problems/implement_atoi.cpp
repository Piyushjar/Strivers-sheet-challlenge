#include <bits/stdc++.h>
using namespace std;

int atoi(string str)
{
    // Write your code here.
    int res = 0;
    for (char c : str)
    {
        if (c >= '0' && c <= '9')
        {
            res *= 10;
            res += c - '0';
        }
    }
    if (str[0] == '-')
        return -res;
    return res;
}