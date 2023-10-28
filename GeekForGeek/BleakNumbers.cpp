#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int countSetBits(int n)
{
    // Base case: If n is 0, it means there are no set bits.
    if (n == 0)
        return 0;

    int count = 0;

    // Count set bits using Brian Kernighan's algorithm.
    while (n)
    {
        count++;
        n = (n & (n - 1)); // Flip the rightmost set bit to 0.
    }

    return count;
}

class Solution
{
public:
    int is_bleak(int n)
    {
        // Iterate from i = (n - 32) to n - 1, to check if there exists a number
        // where i + countSetBits(i) equals n.
        for (int i = max(n - 32, 1); i < n; i++)
        {
            if (i + countSetBits(i) == n)
                return 0; // Not a bleak number.
        }

        return 1; // It's a bleak number.
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