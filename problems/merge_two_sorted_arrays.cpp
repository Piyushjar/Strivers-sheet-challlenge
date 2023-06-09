#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    vector<int> res;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] >= arr2[j])
        {
            res.push_back(arr2[j]);
            j++;
        }
        else
        {
            res.push_back(arr1[i]);
            i++;
        }
    }
    while (i < m)
        res.push_back(arr1[i++]);
    while (j < n)
        res.push_back(arr2[j++]);
    return res;
}