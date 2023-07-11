#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // find the pivot index from the back a[i] < a[i+1]
    int pivot = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (permutation[i] < permutation[i + 1])
        {
            pivot = i;
            break;
        }
    }
    // no pivot found i.e. array is sorted in decreasing order
    if (pivot == -1)
    {
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    // find the next greater element on right side of the pivot index
    for (int i = n - 1; i > pivot; i--)
    {
        if (permutation[i] > permutation[pivot])
        {
            swap(permutation[i], permutation[pivot]);
            break;
        }
    }
    // reverse the right side of pivot
    reverse(permutation.begin() + pivot + 1, permutation.end());
    return permutation;
}