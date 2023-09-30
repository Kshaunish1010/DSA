#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<int> s;       // Initialize a stack to store potential '2' values.
        int mini = INT_MIN; // Initialize a variable to store the minimum value encountered.

        // Traverse the input array from right to left.
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            // If the current element is less than the minimum value encountered so far, return true.
            if (nums[i] < mini)
                return true;
            else
            {
                // While there are elements in the stack and the current element is greater than the top of the stack.
                while (!s.empty() && nums[i] > s.top())
                {
                    mini = s.top(); // Update the minimum value encountered with the top of the stack.
                    s.pop();        // Pop elements from the stack.
                }
            }

            s.push(nums[i]); // Push the current element onto the stack as a potential '2'.
        }

        return false; // If no '132' pattern is found, return false.
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