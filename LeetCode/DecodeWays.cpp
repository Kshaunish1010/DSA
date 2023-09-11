#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    int solve(vector<int> &dp, string s, int i)
    {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ways = 0;
        ways += solve(dp, s, i + 1);
        if (i + 1 < s.size())
        {
            string ch = s.substr(i, 2);
            int x = stoi(ch);
            if (x >= 9 && x < 27)
            {
                ways += solve(dp, s, i + 2);
            }
        }
        return dp[i] = ways;
    }
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        return solve(dp, s, 0);
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