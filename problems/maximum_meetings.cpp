#include <bits/stdc++.h>
using namespace std;

static bool myCmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int>> time;
    for (int i = 0; i < n; i++)
    {
        time.push_back({start[i], end[i]});
    }

    sort(time.begin(), time.end(), myCmp);
    int res = 1;
    int latest = time[0].second;
    for (int i = 1; i < n; i++)
    {
        if (time[i].first > latest)
        {
            res++;
            latest = time[i].second;
        }
    }
    return res;
}
