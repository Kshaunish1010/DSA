#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // Create a frequency map for characters in string t
        unordered_map<char, int> mp;
        for (auto x : t)
        {
            mp[x]++;
        }

        int i = 0, j = 0;              // Two pointers for the sliding window
        int n = s.length();            // Length of string s
        int minLen = INT_MAX;          // Minimum window length
        int minStart = 0;              // Start index of the minimum window
        int requiredChars = mp.size(); // Number of unique characters required
        int formedChars = 0;           // Number of unique characters formed within the window

        while (j < n)
        {
            char currentChar = s[j];

            if (mp.find(currentChar) != mp.end())
            {
                mp[currentChar]--;
                if (mp[currentChar] == 0)
                {
                    formedChars++;
                }
            }

            while (formedChars == requiredChars && i <= j)
            {
                // Check if the current window size is smaller than the minimum found so far
                if (j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                    minStart = i;
                }

                char leftChar = s[i];

                if (mp.find(leftChar) != mp.end())
                {
                    mp[leftChar]++;

                    // If the frequency becomes positive, it means we need more of this character
                    if (mp[leftChar] > 0)
                    {
                        formedChars--;
                    }
                }

                i++; // Move the left pointer to the right
            }

            j++; // Move the right pointer to the right
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
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