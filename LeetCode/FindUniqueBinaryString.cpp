#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    // Function to find a binary string that is different from all given binary strings.
    // Each given binary string has its i-th character equal to the desired binary string's i-th character.
    string findDifferentBinaryString(vector<string>& nums) {
        string result = "";
        
        // Iterate through each binary string in the given vector.
        for (int i = 0; i < nums.size(); i++) {
            // Append the negation of the i-th bit from the i-th binary string to the result.
            // Convert the character '0' or '1' to integer ('0' is 0, '1' is 1) before negation.
            result += '0' + !(nums[i][i] - '0');
        }
        
        return result; // Return the resulting binary string.
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