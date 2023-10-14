#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    int n;

    // Recursive function to find the minimum cost of painting walls.
    int solve(vector<int> &cost, vector<int> &time, vector<vector<int>> &dp, int i, int wallsremaining)
    {
        if (wallsremaining <= 0)
        {
            return 0; // If you've painted the exact number of walls, cost is 0.
        }
        if (i >= n)
        {
            return 1e9; // Set to a large value to represent infeasibility.
        }
        if (dp[i][wallsremaining] != -1)
        {
            return dp[i][wallsremaining]; // Return the cached result if available.
        }
        else
        {
            // Calculate the minimum cost by considering whether to paint the current wall (take) or not (dontake).
            int take = cost[i] + solve(cost, time, dp, i + 1, wallsremaining - time[i] - 1);
            int dontake = solve(cost, time, dp, i + 1, wallsremaining);
            return dp[i][wallsremaining] = min(take, dontake); // Store and return the result.
        }
    }

    // Main function to find the minimum cost of painting walls.
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        n = cost.size(); // Get the total number of walls available.
        int totalWalls = n;
        vector<vector<int>> dp(501, vector<int>(501, -1)); // Initialize a memoization table.
        return solve(cost, time, dp, 0, totalWalls);       // Start the recursive search from the first wall.
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