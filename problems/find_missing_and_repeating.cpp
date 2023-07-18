#include <bits/stdc++.h>
using namespace std;

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    int missEl = -1, repeatEl = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            repeatEl = abs(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            missEl = (i + 1);
            break;
        }
    }
    return {missEl, repeatEl};
}
