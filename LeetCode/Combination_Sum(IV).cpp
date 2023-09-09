#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
    int n;
    int cnt = 0;

public:
    int solve(vector<int> nums, int target, vector<int> dp)
    {
        if (target == 0)
            return 1;
        if (dp[target] != -1)
            return dp[target];
        dp[target] = 0;
        for (auto it : nums)
        {
            if (it <= target)
                dp[target] += solve(nums, target - it, dp);
        }
        return dp[target];
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
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