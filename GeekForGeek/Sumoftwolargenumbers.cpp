#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string findSum(string X, string Y)
    {
        int carry = 0;
        string result = "";
        int i = X.size() - 1;
        int j = Y.size() - 1;

        // Start adding from the rightmost digits of X and Y
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int x = (i >= 0) ? X[i] - '0' : 0;     // Convert character to integer
            int y = (j >= 0) ? Y[j] - '0' : 0;     // Convert character to integer
            int sum = x + y + carry;               // Calculate the sum of digits
            carry = sum / 10;                      // Calculate the carry for the next iteration
            result = to_string(sum % 10) + result; // Append the rightmost digit to the result
            i--;
            j--;
        }

        int leadingZeroes = 0;

        // Find the position of the first non-zero digit in the result
        while (leadingZeroes < result.size() - 1 && result[leadingZeroes] == '0')
        {
            leadingZeroes++;
        }

        // Return the result with leading zeroes removed
        return result.substr(leadingZeroes);
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