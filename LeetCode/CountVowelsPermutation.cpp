#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long // Define a shorthand for "long long" as "ll".

class Solution
{
public:
    vector<vector<ll>> dp;                 // 2D vector for memoization.
    int mod = 1e9 + 7;                     // Define the modulo value.
    int a = 0, e = 1, i = 2, o = 3, u = 4; // Constants for vowel characters: a, e, i, o, u.

    // Recursive function to count vowel permutations.
    ll solve(int ch, int n)
    {
        if (n == 0)
            return 1; // Base case: when n reaches 0, return 1.

        if (dp[ch][n] != -1)
            return dp[ch][n]; // If the result is already calculated, return it from dp array.

        // Calculate permutations based on the current character "ch".
        if (ch == a)
        {
            return dp[ch][n] = (solve(e, n - 1)) % mod; // If 'a', consider only 'e' as the next character.
        }
        else if (ch == e)
        {
            return dp[ch][n] = (solve(a, n - 1) + solve(i, n - 1)) % mod; // If 'e', consider 'a' or 'i' as the next characters.
        }
        else if (ch == i)
        {
            return dp[ch][n] = (solve(a, n - 1) + solve(e, n - 1) + solve(o, n - 1) + solve(u, n - 1)) % mod; // If 'i', consider 'a', 'e', 'o', or 'u' as the next characters.
        }
        else if (ch == o)
        {
            return dp[ch][n] = (solve(i, n - 1) + solve(u, n - 1)) % mod; // If 'o', consider 'i' or 'u' as the next characters.
        }
        else
        {
            return dp[ch][n] = (solve(a, n - 1)) % mod; // If 'u', consider only 'a' as the next character.
        }

        return dp[ch][n] = 0; // Default case, return 0.
    }

    // Main function to count vowel permutations for a given n.
    int countVowelPermutation(int n)
    {
        dp.resize(5, vector<ll>(n + 1, -1)); // Initialize the memoization array with -1.
        long result = 0;
        result = (result + solve(a, n - 1)) % mod; // Count permutations starting with 'a'.
        result = (result + solve(e, n - 1)) % mod; // Count permutations starting with 'e'.
        result = (result + solve(i, n - 1)) % mod; // Count permutations starting with 'i'.
        result = (result + solve(o, n - 1)) % mod; // Count permutations starting with 'o'.
        result = (result + solve(u, n - 1)) % mod; // Count permutations starting with 'u'.
        return result;                             // Return the total number of vowel permutations.
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