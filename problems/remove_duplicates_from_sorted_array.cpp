#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n)
{
    // Write your code here.
    int slow = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[slow] != arr[i])
            arr[++slow] = arr[i];
    }
    return slow + 1;
}