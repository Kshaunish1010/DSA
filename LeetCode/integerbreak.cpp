#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> dp; // Memoization array to store computed results.

    // Recursive function to find the maximum product of integers that sum up to n.
    int solve(int n)
    {
        if (n == 1) // Base case: If n is 1, return 1 (cannot break it further).
            return 1;

        if (dp[n] != -1) // If the result for n is already computed, return it.
            return dp[n];

        int result = INT_MIN; // Initialize the result to a very small value.

        for (int i = 1; i <= n - 1; i++) // Try breaking n into two integers (i and n - i).
        {
            int prod = i * max(n - i, solve(n - i)); // Calculate the product.

            result = max(result, prod); // Update the result with the maximum product found.
        }

        return dp[n] = result; // Store the result in the memoization array and return it.
    }

    int integerBreak(int n)
    {
        dp.resize(n + 1, -1); // Initialize the memoization array with -1 values.

        return solve(n); // Start the recursion to find the maximum product.
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