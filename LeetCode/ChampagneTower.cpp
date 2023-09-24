#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    double solve(vector<vector<double>> &dp, int poured, int i, int j)
    {
        // Base cases
        if (i < 0 || j > i || j < 0)
        {
            return 0.0;
        }

        if (i == 0 && j == 0)
        {
            return dp[i][j] = poured;
        }

        // If already computed, return the result from the memoization table
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Calculate the amount of champagne from upper left and upper right glasses
        double upLeft = (solve(dp, poured, i - 1, j - 1) - 1) / 2.0;
        double upRight = (solve(dp, poured, i - 1, j) - 1) / 2.0;

        // Ensure non-negative values
        if (upLeft < 0)
        {
            upLeft = 0.0;
        }

        if (upRight < 0)
        {
            upRight = 0.0;
        }

        // Store the calculated value in the memoization table and return
        return dp[i][j] = upLeft + upRight;
    }

    double champagneTower(int poured, int query_row, int query_glass)
    {
        // Create a memoization table initialized with -1
        vector<vector<double>> dp(101, vector<double>(101, -1.0));

        // Call the recursive solve function and return the result
        return min(1.0, solve(dp, poured, query_row, query_glass));
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