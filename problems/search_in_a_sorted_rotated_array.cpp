#include <bits/stdc++.h>
using namespace std;

int search(int *arr, int n, int target)
{
    // Write your code here.
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (arr[m] == target)
            return m;
        if (arr[m] >= arr[0])
        { // left side
            if (arr[0] <= target && target <= arr[m])
                h = m - 1;
            else
                l = m + 1;
        }
        else
        { // right side
            if (arr[n - 1] >= target && target >= arr[m])
                l = m + 1;
            else
                h = m - 1;
        }
    }
    return -1;
}