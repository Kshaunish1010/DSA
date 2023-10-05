#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int candidate1 = 0, candidate2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (candidate1 == nums[i])
            {
                cnt1++;
            }
            else if (candidate2 == nums[i])
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                candidate1 = nums[i];
                cnt1++;
            }
            else if (cnt2 == 0)
            {
                candidate2 = nums[i];
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == candidate1)
                cnt1++;
            if (nums[i] == candidate2)
                cnt2++;
        }
        vector<int> ans;
        if (cnt1 > n / 3 && cnt2 > n / 3)
        {
            ans.push_back(candidate1);
            ans.push_back(candidate2);
        }
        else if (cnt1 > n / 3)
            ans.push_back(candidate1);
        else if (cnt2 > n / 3)
            ans.push_back(candidate2);
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