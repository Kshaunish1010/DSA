#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0;
        int n = height.size();
        int r = n - 1;
        int area = INT_MIN;
        while (l < r)
        {
            int mini = min(height[l], height[r]);
            area = max(area, mini * (r - l));
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return area;
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