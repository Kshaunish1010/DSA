#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        unordered_map<char, int> mp;
        for (auto x : p)
        {
            mp[x]++;
        }
        int requiredCount = p.length();
        int n = s.length();
        int i = 0, j = 0;
        int minStart = 0;
        int minWindow = INT_MAX;
        while (j < n)
        {
            char ch_j = s[j];
            if (mp[ch_j] > 0)
                requiredCount--;

            mp[ch_j]--;

            while (requiredCount == 0)
            { // try to shrink the window
                if (minWindow > j - i + 1)
                {
                    minWindow = j - i + 1;
                    minStart = i;
                }

                char ch_i = s[i];
                mp[ch_i]++;
                if (mp[ch_i] > 0)
                    requiredCount++;
                i++;
            }

            j++; // Don't ever forget this :-)
        }

        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
        // Your code here
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