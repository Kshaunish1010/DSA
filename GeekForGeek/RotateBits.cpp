#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> rotate(int n, int d)
    {
        const int bits = 16; // Number of bits in the integer representation (assuming 16 bits)
        d = d % bits;        // Ensure d is within the range [0, 15]

        if (d == 0)
        {
            // If d is 0, there is no rotation, so return the original number twice
            return {n, n};
        }

        int limit = (1 << bits) - 1;                              // Calculate the limit for the bit manipulation
        int leftRotate = ((n << d) | (n >> (bits - d))) & limit;  // Left rotation
        int rightRotate = ((n >> d) | (n << (bits - d))) & limit; // Right rotation

        return {leftRotate, rightRotate}; // Return the left and right rotations
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