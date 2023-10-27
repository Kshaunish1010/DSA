#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int n;

    // Recursive function to find the minimum number of deletions to make S a palindrome.
    int solve(string S, string T, int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (S[i - 1] == T[j - 1])
        {
            // If characters at positions i and j match, increment the count and move to the next characters.
            return 1 + solve(S, T, i - 1, j - 1, dp);
        }

        int c2 = solve(S, T, i - 1, j, dp); // Delete character from S.
        int c3 = solve(S, T, i, j - 1, dp); // Delete character from T.

        // Return the maximum of deletion options.
        return dp[i][j] = max(c2, c3);
    }

    // Main function to find the minimum number of deletions to make S a palindrome.
    int minimumNumberOfDeletions(string S)
    {
        n = S.length();                                        // Length of the string.
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1)); // Initialize the memoization table.
        string T = S;
        reverse(S.begin(), S.end());     // Reverse the string to create T.
        int cnt = solve(S, T, n, n, dp); // Find the count of matching characters.
        return n - cnt;                  // Return the difference between the string length and the count.
    }
};
// tabulation
class Solution
{
public:
    int minimumNumberOfDeletions(string S)
    {
        int n = S.length();                                   // Length of the string.
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // Initialize the memoization table.
        string T = S;
        reverse(S.begin(), S.end()); // Reverse the string to create T.

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (S[i - 1] == T[j - 1])
                {
                    // If characters at positions i and j match, increment the count and move diagonally.
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    // If characters don't match, choose the maximum count from the cell above or the cell to the left.
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // The difference between the string length and the count in the bottom-right cell represents the minimum deletions needed.
        return n - dp[n][n];
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