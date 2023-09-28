#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] % 2 != 0)
            {
                while (j > i && nums[j] % 2 != 0)
                {
                    j--;
                }
                if (j < i)
                    break;
                swap(nums[i], nums[j]);
            }
            if (nums[i] % 2 == 0)
                i++;
            if (nums[j] % 2 != 0)
                j--;
        }
        return nums;
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