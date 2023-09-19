#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        // Initialize two pointers, slow and fast, both starting at the first element
        int slow = nums[0];
        int fast = nums[0];
        
        // Phase 1: Detect the intersection point of the two pointers
        do {
            // Move slow one step at a time
            slow = nums[slow];
            // Move fast two steps at a time
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Phase 2: Find the entrance to the cycle
        // Reset one of the pointers to the beginning while keeping the other at the intersection point
        fast = nums[0];
        while (slow != fast) {
            // Move both pointers one step at a time until they meet at the entrance of the cycle
            slow = nums[slow];
            fast = nums[fast];
        }
        
        // The intersection point is the duplicate element
        return slow;
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