#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    int n; // Variable to store the size of the 'cost' vector.

    // Recursive function to find the minimum cost to reach the i-th step.
    int solve(vector<int> &cost, int i, vector<int> &dp)
    {
        if (i < 0)
            return 0; // Base case: If 'i' is negative, no cost is incurred.

        // Base case: If 'i' is 0 or 1, return the cost at that step.
        if (i == 0 || i == 1)
            return cost[i];

        if (dp[i] != 0)
            return dp[i]; // If the value is already calculated, return it from the 'dp' array.

        // Calculate the minimum cost to reach the i-th step by considering two options:
        // 1. Go from the (i-1)-th step.
        // 2. Go from the (i-2)-th step.
        dp[i] = cost[i] + min(solve(cost, i - 1, dp), solve(cost, i - 2, dp));

        return dp[i];
    }

    // Main function to find the minimum cost of climbing stairs with given costs.
    int minCostClimbingStairs(vector<int> &cost)
    {
        n = cost.size();      // Store the size of the 'cost' vector.
        vector<int> dp(n, 0); // Initialize a 'dp' vector with size 'n' to store calculated values.

        // Return the minimum cost of reaching the top by considering the last two steps.
        return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }
};

//optimised code
class Solution {
public:
    // Function to find the minimum cost of climbing stairs with given costs.
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); // Get the number of steps (size of the 'cost' vector).

        // Iterate through the steps starting from the 3rd step (index 2).
        for (int i = 2; i < n; i++) {
            // Update the cost of the current step by adding the minimum cost of
            // either coming from the previous step or two steps back.
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }

        // Return the minimum cost of reaching the top, which is the minimum cost
        // of the last two steps (n-1 and n-2).
        return min(cost[n - 1], cost[n - 2]);
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