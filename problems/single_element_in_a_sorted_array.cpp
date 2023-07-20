#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    // Write your code here
    int low = 0, high = nums.size() - 1, mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (nums[mid ^ 1] == nums[mid])
            low = mid + 1;
        else
            high = mid;
    }
    return nums[low];
}