#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
class Solution
{
public:
    int isPerfectNumber(ll n)
    {
        ll sum = 1;
        for (ll i = 2; i * i < n; i++)
        {
            if (n % i == 0)
                sum += i + n / i;
        }
        if (n != 1 && sum == n)
            return 1;
        return 0;
        // code here
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