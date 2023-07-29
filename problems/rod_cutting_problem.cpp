#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int solve(vector<int> &price, int idx, int len)
{
	if (idx == 0)
		return len * price[0];

	if (dp[idx][len] != -1)
		return dp[idx][len];

	// not cut
	int notCut = solve(price, idx - 1, len);

	// cut
	int cut = INT_MIN;
	int rod_len = idx + 1;
	if (rod_len <= len)
		cut = price[idx] + solve(price, idx, len - rod_len);

	return dp[idx][len] = max(notCut, cut);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	memset(dp, -1, sizeof(dp));
	return solve(price, n - 1, n);
}
