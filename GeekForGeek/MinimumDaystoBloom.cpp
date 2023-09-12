#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int m;
    bool isValid(vector<int> &roses, int k, int n, int mid)
    {
        int b = 0;
        int cnt = 0, j = 0;
        while (j < m)
        {
            if (mid >= roses[j])
            {
                cnt++;
                j++;
            }
            else
            {
                b += (cnt / k);
                cnt = 0;
                while (j < m && roses[j] > mid)
                    j++;
            }
        }
        if (cnt != 0)
            b += (cnt / k);
        if (b >= n)
            return true;
        return false;
    }
    int findMinDays(vector<int> &roses, int k, int n)
    {
        m = roses.size();
        int maxi = *max_element(roses.begin(), roses.end());
        int mini = *min_element(roses.begin(), roses.end());
        int ans = 0;
        while (mini <= maxi)
        {
            int mid = mini + (maxi = mini) / 2;
            if (isValid(roses, k, n, mid))
            {
                ans = mid;
                maxi = mid - 1;
            }
            else
                mini = mid + 1;
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