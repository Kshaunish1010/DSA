#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    string decodeAtIndex(string s, int k)
    {
        long long n = 0, i = 0;

        // Calculate the total length, 'n', of the decoded string.
        for (; n < k; i++)
        {
            if (isdigit(s[i]))
            {
                n = n * (s[i] - '0'); // If a digit is encountered, multiply 'n' by its numeric value.
            }
            else
            {
                n++; // If a character is encountered, increment 'n' by 1.
            }
        }

        // Backtrack to find the k-th character.
        while (i--)
        {
            if (isdigit(s[i]))
            {
                n = n / (s[i] - '0'); // If a digit is encountered while backtracking, divide 'n' by its numeric value.
                k = k % n; // Update 'k' to be the remainder when divided by 'n'.
            }
            else if (k % n == 0)
            {
                return string(1, s[i]); // If 'k' is divisible by 'n', return the current character.
            }
            else n--; // reduce if character is found
        }

        return ""; // If no character is found, return an empty string.
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