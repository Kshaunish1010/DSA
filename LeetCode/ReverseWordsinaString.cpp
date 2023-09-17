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
        int n = s.size(), i = 0, j = 0;
        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++;
            if (i < n && j > 0)
                s[j++] = ' ';
            int start = j;
            while (i < n && s[i] != ' ')
                s[j++] = s[i++];
            reverse(s.begin() + start, s.begin() + j);
        }
        s.resize(j);
        reverse(s.begin(), s.end());
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