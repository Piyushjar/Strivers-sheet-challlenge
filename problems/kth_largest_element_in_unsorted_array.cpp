#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> &arr, int size, int K)
{
    // Write your code here.
    priority_queue<int> pq(arr.begin(), arr.end());
    while (K > 1)
    {
        pq.pop();
        K--;
    }
    return pq.top();
}