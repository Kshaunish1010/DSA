#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int nCr(int n, int r)
{
    long long int m = 1000000007;
    long long int inv[r + 1] = {0};
    inv[0] = 1;
    if (r + 1 >= 2)
        inv[1] = 1;

    for (int i = 2; i <= r; i++)
    {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }

    int ans = 1;

    for (int i = 2; i <= r; i++)
    {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }

    for (int i = n; i >= (n - r + 1); i--)
    {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}
long long getAnswer(long long a[], long long n, long long k, long long x)
{
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i <= n - k; i++)
    {
        int idx = lower_bound(a, a + n, a[i] + x + 1) - a - 1;
        if (idx - i + 1 < k)
            continue;
        long long count = nCr(idx - i, k - 1);
        ans = (ans + count) % 1000000007;
    }
    return ans;
}
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