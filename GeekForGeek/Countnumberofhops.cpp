#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
int mod = 1e9 + 7;
class Solution
{
public:
    int n;
    ll solve(vector<ll> &dp, int i)
    {
        if (i > n)
            return 0;
        if (i == n)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        int x = solve(dp, i + 1);
        int y = solve(dp, i + 2);
        int z = solve(dp, i + 3);
        return dp[i] = ((((x % mod) + (y % mod)) % mod + (z % mod)) % mod) % mod;
    }
    // Function to count the number of ways in which frog can reach the top.
    ll countWays(int n)
    {
        this->n = n;
        vector<ll> dp(n + 1, -1);
        return solve(dp, 0);
        // your code here
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