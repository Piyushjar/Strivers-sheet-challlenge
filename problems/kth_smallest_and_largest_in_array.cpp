#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    return {arr[k - 1], arr[n - k]};
}