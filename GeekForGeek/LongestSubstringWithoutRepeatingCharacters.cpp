#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0, cnt = 0;   // Initialize two pointers i and j.
        int n = s.length();          // Get the length of the input string.
        int ans = 0;                 // Initialize the result to a minimum value.
        unordered_map<char, int> mp; // Create a hashmap to store characters and their indexes.

        while (j < n)
        { // Loop while the right pointer (j) is within the bounds of the string.
            if (!mp.count(s[j]) || mp[s[j]] < i)
            {
                // If the character at j is not in the hashmap or its index is less than i (not in the current window).
                mp[s[j]] = j;              // Update the hashmap with the character's index.
                ans = max(ans, j - i + 1); // Update the maximum substring length.
                j++;                       // Move the right pointer to the next character.
            }
            else
            {
                // If the character at j is already in the current window.
                i = mp[s[j]] + 1; // Update the left pointer to skip the repeated character.
            }
        }
        return ans; // Return the length of the longest substring without repeating characters.
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