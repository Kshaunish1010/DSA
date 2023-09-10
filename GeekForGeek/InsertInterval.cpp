#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// User function Template for C++

class Solution
{
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> newInterval)
    {
        // Code Here
        int n = intervals.size();
        vector<vector<int>> result;
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0])
        {
            result.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        result.push_back(newInterval);
        for (; i < n; i++)
            result.push_back(intervals[i]);
        return result;
    }
};
int main()
{
    turbo;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}