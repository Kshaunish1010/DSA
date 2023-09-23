#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // Helper function to check if two words are consecutive in the chain.
    bool compare(string a, string b)
    {
        // To be consecutive, the difference in size should be exactly 1.
        if (a.size() != b.size() + 1)
            return false;
        int i = 0, j = 0;
        while (i < a.size())
        {
            if (j < b.size() && a[i] == b[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        // If 'i' reached the end of 'a' and 'j' reached the end of 'b', they are consecutive.
        return (i == a.size() && j == b.size());
    }

    // Custom comparator for sorting words based on their lengths.
    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string> &words)
    {
        int n = words.size();

        // Sort words by their lengths in ascending order.
        sort(words.begin(), words.end(), comp);

        // Initialize a dynamic programming array to store the longest chain length for each word.
        vector<int> dp(n, 1);

        int maxi = 1; // Variable to track the maximum chain length.

        // Iterate through the words.
        for (int i = 1; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                // If 'words[i]' can be formed by removing one character from 'words[prev]'
                // and results in a longer chain, update the chain length for 'words[i]'.
                if (compare(words[i], words[prev]) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = dp[prev] + 1;
                }

                // Update 'maxi' with the maximum chain length found so far.
                if (dp[i] > maxi)
                {
                    maxi = dp[i];
                }
            }
        }

        return maxi; // Return the maximum chain length found.
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