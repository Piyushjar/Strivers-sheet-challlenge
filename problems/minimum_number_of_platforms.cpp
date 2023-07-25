#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);
    int i = 1, j = 0;
    int curr = 1, maxPlatform = 1;
    while (i < n && j < n)
    {
        if (at[i] <= dt[j])
        {
            curr++;
            i++;
            maxPlatform = max(maxPlatform, curr);
        }
        else
        {
            curr--;
            j++;
        }
    }
    return maxPlatform;
}