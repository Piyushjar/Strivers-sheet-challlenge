#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    // kadane algoritm
    long long sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        res = max(res, sum);
        if (sum < 0)
            sum = 0;
    }
    return res;
}