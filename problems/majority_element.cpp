#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n)
{
    int count = 1, idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[idx])
            count++;
        else
            count--;
        if (count == 0)
        {
            count = 1;
            idx = i;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[idx])
            count++;
    }
    if (count > n / 2)
        return arr[idx];
    return -1;
}