#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> mxr;
    vector<int> mxl;
    int n;
    void maxRight(vector<int> &height)
    {
        int mx = height[n-1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (mx < height[i])
                mx = height[i];
            mxr.push_back(mx);
        }
        reverse(mxr.begin(), mxr.end());
    }
    void maxLeft(vector<int> &height)
    {
        int mx = height[0];
        for (int i = 0; i < n; i++)
        {
            if (mx < height[i])
                mx = height[i];
            mxl.push_back(mx);
        }
    }
    int trap(vector<int> &height)
    {
        n = height.size();
        maxRight(height);
        maxLeft(height);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += min(mxr[i], mxl[i]) - height[i];
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