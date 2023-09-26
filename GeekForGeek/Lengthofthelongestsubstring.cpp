#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int longestUniqueSubsttr(string S)
    {
        int n = S.length();
        vector<int> lastIndex(256, -1); // Initialize an array to store the last known index of each character (assuming ASCII characters).

        int ans = 0; // Initialize the answer to 0.
        int i = 0;   // Initialize the start of the current substring.

        for (int j = 0; j < n; j++)
        {
            char curr = S[j]; // Get the current character.

            // If the character is encountered again in the current substring, update the start of the substring.
            if (lastIndex[curr] != -1 && lastIndex[curr] >= i)
            {
                i = lastIndex[curr] + 1;
            }

            // Update the last known index of the character.
            lastIndex[curr] = j;

            // Update the answer with the maximum length found so far.
            ans = max(ans, j - i + 1);
        }

        return ans; // Return the maximum length of the substring with unique characters.
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