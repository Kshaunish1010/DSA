#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x)
    {
        vector<int> ans(2);
        int i = 0, j = m - 1, mindiff = INT_MAX;
        while (i < n && j >= 0)
        {
            int sum = arr[i] + brr[j];
            if (mindiff > abs(sum - x))
            {
                mindiff = abs(sum - x);
                ans[0] = arr[i];
                ans[1] = brr[j];
            }
            if (sum < x)
                i++;
            else
                j--;
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