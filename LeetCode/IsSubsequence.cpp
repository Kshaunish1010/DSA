#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int n, m;
    bool solve(string s, string t, int i, int j)
    {
        if (j == m)
            return 1;
        if (i == n)
            return 0;
        if (s[j] == t[i])
            return solve(s, t, i + 1, j + 1);
        else
            return solve(s, t, i + 1, j);
    }
    bool isSubsequence(string s, string t)
    {
        n = t.length(), m = s.length();
        return solve(s, t, 0, 0);
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