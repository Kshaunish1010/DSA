#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int mod = 1e9 + 7; // Modulus value for handling large numbers

    int distinctSubsequences(string s)
    {
        int n = s.size(); // Get the length of the input string

        vector<int> last(26, -1); // Initialize an array to store the last occurrence index of each character
        long long dp[n + 1];      // Initialize an array to store dynamic programming values
        dp[0] = 1;                // There is one way to form an empty subsequence

        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] * 2; // The number of subsequences doubles by adding one more character

            int lastOccur = last[s[i - 1] - 'a']; // Get the last occurrence index of the current character

            if (lastOccur != -1)
            {                           // If the character has occurred before
                dp[i] -= dp[lastOccur]; // Subtract the number of subsequences that include the previous occurrence
                if (dp[i] < 0)
                    dp[i] += mod; // Ensure dp[i] is non-negative
            }

            dp[i] %= mod;                 // Apply modulus to keep the result within the specified range
            last[s[i - 1] - 'a'] = i - 1; // Update the last occurrence index of the current character
        }

        return dp[n]; // Return the total number of distinct subsequences
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