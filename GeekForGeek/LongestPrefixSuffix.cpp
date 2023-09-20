#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int lps(string s)
    {
        int n = s.length(); // Length of the input string
        int len = 0;        // Length of the longest proper prefix which is also a proper suffix
        int i = 1;          // Start from the second character of the string

        vector<int> lpsArray(n, 0); // Create an array to store Longest Prefix Suffix values

        while (i < n)
        {
            if (s[i] == s[len])
            {
                len++;             // Increment length when characters match
                lpsArray[i] = len; // Store the length in the LPS array
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lpsArray[len - 1]; // If characters don't match, update length using LPS array
                }
                else
                {
                    lpsArray[i] = 0; // If no match and length is 0, set LPS value to 0
                    i++;
                }
            }
        }

        return lpsArray[n - 1]; // Return the LPS value for the last character of the string
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