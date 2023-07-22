#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> res(n, 0);
    res[n - 1] = -1;
    s.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= arr[i])
            s.pop();
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return res;
}