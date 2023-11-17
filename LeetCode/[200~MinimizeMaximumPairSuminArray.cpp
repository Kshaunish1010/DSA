#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        int sum = INT_MIN;
        while (i < j)
        {
            sum = max(sum, nums[i] + nums[j]);
            i++;
            j--;
        }
        return sum;
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