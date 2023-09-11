#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool isValid(int arr[], int k, int n, int mid)
    {
        int sum = 0;
        int sub = 1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                sub++;
                sum = arr[i];
            }
            if (sub > k)
                return false;
        }
        return true;
    }
    int splitArray(int arr[], int n, int k)
    {
        int maxi = INT_MIN, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (maxi < arr[i])
                maxi = arr[i];
        }
        int l = maxi;
        int h = sum;
        int ans = -1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (isValid(arr, k, n, mid))
            {
                // cout<<mid;
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