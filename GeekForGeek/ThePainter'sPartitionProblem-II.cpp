#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
class Solution
{
public:
    bool isValid(int arr[], int k, int n, ll mid)
    {
        ll sum = 0;
        int painter = 1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                painter++;
                sum = arr[i];
            }
            if (painter > k)
                return false;
        }
        return true;
    }
    ll minTime(int arr[], int n, int k)
    {
        ll maxi = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (maxi < arr[i])
                maxi = arr[i];
        }
        ll l = maxi;
        ll h = sum;
        ll ans = -1;
        while (l <= h)
        {
            ll mid = l + (h - l) / 2;
            if (isValid(arr, k, n, mid))
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
        // code here
        // return minimum time
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