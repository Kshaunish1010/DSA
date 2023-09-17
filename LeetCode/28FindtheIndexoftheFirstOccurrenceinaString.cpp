#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int i = 0, j = 0;
        int n = haystack.length(), m = needle.length();

        while (i < n)
        {
            if (haystack[i] == needle[j])
            {
                int k = i;
                while (k < n && j < m && haystack[k] == needle[j])
                {
                    k++;
                    j++;
                }

                // Check if the entire needle was found
                if (j == m)
                    return i;

                // Reset j to 0 for the next attempt
                j = 0;
            }

            i++;
        }

        // If the needle was not found, return -1
        return (j == m) ? i - m : -1;
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