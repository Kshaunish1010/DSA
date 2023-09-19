#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // Function to find position of the first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        unsigned int pos = 1; // Initialize the position to 1

        while (n > 0)
        {
            if (n & 1)
            {
                // Check if the least significant bit (LSB) is set to 1
                // If set, return the current position as the first set bit position
                return pos;
            }

            n >>= 1; // Right-shift n to check the next bit
            pos++;   // Increment the position for the next bit
        }

        // If no set bit is found in the entire binary representation of 'n'
        // Return 0 to indicate that there are no set bits
        return -1;
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