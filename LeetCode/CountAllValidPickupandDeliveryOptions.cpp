#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
ll MOD = 1e9 + 7;
class Solution
{
public:
    int countOrders(int n)
    {
        ll ans = 1;
        for (int i = 2; i <= n; i++)
        {
            ans = (ans * (2 * i - 1) * i) % MOD;
        }
        return ans;
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