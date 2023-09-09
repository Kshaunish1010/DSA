#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
            {
                while (arr[l] != x && arr[r] != x)
                {
                    l++;
                    r--;
                }
                while (arr[l] != x)
                {
                    l++;
                }
                while (arr[r] != x)
                {
                    r--;
                }
                break;
            }
            if (arr[mid] > x)
                r = mid - 1;
            if (arr[mid] < x)
                l = mid + 1;
        }
        if (arr[l] == x && arr[r] == x)
            return r - l + 1;
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }

    // cerr<< "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}