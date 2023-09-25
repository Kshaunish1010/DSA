#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // Recursive function to generate lexical order
    void solve(vector<int> &ans, int nums, int n)
    {
        // Base case: if the number exceeds n, return
        if (nums > n)
            return;

        // Add the current number to the result vector
        ans.push_back(nums);

        // Recursively call solve for the next level in the lexical order
        solve(ans, nums * 10, n);

        // If the last digit is not 9, increment it and call solve
        if (nums % 10 != 9)
            solve(ans, nums + 1, n);
    }

    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;

        // Start the recursion from 1
        solve(ans, 1, n);

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