#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // Recursive function to find the maximum money the thief can get.
    int solve(int arr[], vector<int> &dp, int i, int n)
    {
        // Base case: if the thief is out of bounds, return 0.
        if (i >= n)
            return 0;

        // If the maximum money for the current position is already calculated, return it.
        if (dp[i] != -1)
            return dp[i];

        // Calculate the maximum money the thief can get if they don't take the current house (ntk).
        int ntk = solve(arr, dp, i + 1, n);

        // Calculate the maximum money the thief can get if they take the current house (tk).
        int tk = arr[i] + solve(arr, dp, i + 2, n);

        // Return the maximum of ntk and tk as the result and store it in dp.
        return dp[i] = max(ntk, tk);
    }

    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Create a vector to store previously calculated maximum money values with -1 as the initial value.
        vector<int> dp(n + 1, -1);

        // Call the solve function to find the maximum money starting from the first house (index 0).
        return solve(arr, dp, 0, n);
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