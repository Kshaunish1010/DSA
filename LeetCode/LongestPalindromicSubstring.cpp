#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(); // Get the length of the input string.
        vector<vector<bool>> t(n, vector<bool>(n, false)); // Create a table to store palindrome information.
        int maxL = 1; // Initialize the maximum length to 1.
        int start = 0; // Initialize the starting index of the longest palindrome.

        // Initialize the table for single characters, which are always palindromes.
        for(int i = 0; i < n; i++)
            t[i][i] = true;

        // Fill in the table for longer palindromes.
        for(int L = 2; L <= n; L++) {
            for(int i = 0; i < n - L + 1; i++) {
                int j = i + L - 1;

                // Check if the characters at both ends of the substring match and the inner substring is also a palindrome.
                if(s[i] == s[j] && (t[i+1][j-1] || L == 2)) {
                    t[i][j] = true;

                    // Update the maximum length and starting index if a longer palindrome is found.
                    if(L > maxL) {
                        maxL = L;
                        start = i;
                    }
                }
            }
        }

        // Return the longest palindromic substring by using the starting index and maximum length.
        return s.substr(start, maxL);
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