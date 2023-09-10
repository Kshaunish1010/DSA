#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// User function Template for C++
class Solution
{
public:
    long long solve(int n, vector<int> a, long long k)
    {
        int i = 0, j = 0;
        long long ans = 0, sum = 0;
        while (j < n)
        {
            sum += a[j];
            while (sum > k)
            {
                sum -= a[i];
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
    long long countSubarray(int n, vector<int> a, long long L, long long R)
    {
        // code here
        return solve(n, a, R) - solve(n, a, L - 1);
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