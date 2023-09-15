#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int n;
    int solve(int arr[], vector<vector<int>> &dp, int sum, int i)
    {
        if (i == n)
            return (sum == 0) ? 1 : 0;
        if (sum == 0)
            return 1;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        int p = 0;
        if (arr[i] <= sum)
        {
            p = solve(arr, dp, sum - arr[i], i + 1);
        }
        int np = solve(arr, dp, sum, i + 1);
        return dp[i][sum] = p | np;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        this->n = N;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return 0;
        sum /= 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(arr, dp, sum, 0);
        // code here
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