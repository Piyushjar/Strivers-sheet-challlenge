#include <bits/stdc++.h>
using namespace std;

long long getTrappedWater(long long *arr, int n)
{
    long long res = 0;
    vector<long long> leftMax(n, 0), rightMax(n, 0);
    leftMax[0] = arr[0];
    rightMax[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        res += min(leftMax[i], rightMax[i]) - arr[i];
    }
    return res;
}