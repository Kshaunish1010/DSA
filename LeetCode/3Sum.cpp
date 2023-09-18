#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 3)
            return ans;
        for (int i = 0; i < n; i++)
        {
            int l = i + 1;
            int h = n - 1;
            int find = -1 * nums[i];
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while (l < h)
            {
                if (nums[l] + nums[h] == find)
                {
                    vector<int> temp = {nums[l], nums[i], nums[h]};
                    ans.push_back(temp);
                    while (l < h && nums[l] == nums[l + 1])
                        l++;
                    while (l < h && nums[h] == nums[h - 1])
                        h--;
                    l++;
                    h--;
                }
                else if (nums[l] + nums[h] < find)
                    l++;
                else
                    h--;
            }
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