#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> find(int arr[], int n, int x)
    {
        int l = 0, r = n - 1;
        vector<int> ans(2, -1);
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
            {
                while (arr[l] != x)
                {
                    l++;
                }
                while (arr[r] != x)
                {
                    r--;
                }
                ans[0] = l;
                ans[1] = r;
                break;
            }
            else if (arr[mid] > x)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
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