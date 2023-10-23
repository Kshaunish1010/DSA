#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
//  GIVES TLE
class Solution
{

public:
    int n;
    int solve(int arr[], vector<vector<int>> &dp, int i, int prev)
    {
        if (i == n)
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int sum1 = solve(arr, dp, i + 1, prev);
        int sum2 = -1e7;
        if (prev == -1 || arr[i] > arr[prev])
        {
            sum2 = arr[i] + solve(arr, dp, i + 1, i);
        }
        return dp[i][prev + 1] = max(sum1, sum2);
    }
    int maxSumIS(int arr[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        this->n = n;
        return solve(arr, dp, 0, -1);
        // Your code goes here
    }
};
// OPTIMISED
class Solution
{
public:
    int maxSumIS(int arr[], int n)
    {
        // Create a dynamic programming array to store the maximum sum at each index.
        vector<int> dp(n, 0);

        int ans = 0; // Initialize the maximum sum.

        for (int i = 0; i < n; ++i)
        {
            dp[i] = arr[i]; // Initialize dp[i] with the value of the current element.

            // Iterate over previous elements to find the maximum increasing subsequence sum.
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] < arr[i])
                {
                    // If the current element is greater than the previous one,
                    // update dp[i] with the maximum sum found so far.
                    dp[i] = max(dp[i], arr[i] + dp[j]);
                }
            }

            // Update the overall maximum sum if dp[i] is larger.
            ans = max(ans, dp[i]);
        }

        return ans; // Return the maximum increasing subsequence sum.
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