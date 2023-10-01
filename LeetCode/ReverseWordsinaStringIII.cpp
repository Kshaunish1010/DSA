#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        int start = 0;

        // Iterate through the string
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                // When a space is encountered, reverse the word from 'start' to 'i'
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1; // Update the start index for the next word
            }
        }

        // Reverse the last word (or the only word if there are no spaces)
        reverse(s.begin() + start, s.end());

        return s;
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