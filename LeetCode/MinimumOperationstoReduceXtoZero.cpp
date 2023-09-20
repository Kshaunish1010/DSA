#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int n = nums.size();
        // Calculate the target sum by subtracting x from the total sum of nums
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        
        // If target is 0, return the total number of elements in nums
        if (target == 0)
            return n;
        
        int maxOps = INT_MIN, i = 0, sum = 0;
        
        // Iterate through nums with two pointers (i and j)
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            
            // Shrink the window from the left (i) if sum exceeds target
            while (i < j && sum > target) {
                sum -= nums[i];
                i++;
            }
            
            // If the current window sum equals the target, update maxOps
            if (sum == target) {
                maxOps = max(maxOps, j - i + 1);
            }
        }
        
        // If no valid window was found, return -1; otherwise, return the minimum operations
        return (maxOps == INT_MIN) ? -1 : n - maxOps;
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
