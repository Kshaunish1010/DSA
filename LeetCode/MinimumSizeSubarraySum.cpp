#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, ans = INT_MAX;
        while (j < n)
        {
            sum += nums[j];
            while (sum >= target)
            {
                ans = min(ans, (j - i + 1));
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (ans == INT_MAX) ? 0 : ans;
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