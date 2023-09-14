#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int mod = 1e9 + 7;
class Solution
{

public:
    int n;
    int solve(int arr[], vector<vector<int>> &dp, int sum, int i)
    {
        if (i == n)
            return (sum == 0) ? 1 : 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        int y = 0;
        if (arr[i] <= sum)
        {
            y = solve(arr, dp, sum - arr[i], i + 1);
        }
        int x = solve(arr, dp, sum, i + 1);
        return dp[i][sum] = (x % mod + y % mod) % mod;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        this->n = n;
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(arr, dp, sum, 0);
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