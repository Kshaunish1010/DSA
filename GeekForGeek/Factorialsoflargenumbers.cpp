#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    void multiply(vector<int> &ans, int p)
    {
        int carry = 0;

        // Multiply each digit of 'a' with 'b' and add carry from previous iteration.
        for (int i = 0; i < ans.size(); i++)
        {
            int prod = ans[i] * p + carry;
            ans[i]=prod % 10; // Add the last digit of the product.
            carry = prod / 10;           // Set carry for the next iteration.
        }

        // If there's a carry left, add it to the result.
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
    }

    vector<int> factorial(int N)
    {
        vector<int> ans;
        ans.push_back(1); // Initialize ans as 1, representing 1!

        // Calculate factorial by multiplying with each number from 2 to N.
        for (int i = 2; i <= N; i++)
        {
            multiply(ans, i);
        }

        // Reverse the result to get the correct factorial representation.
        reverse(ans.begin(), ans.end());
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