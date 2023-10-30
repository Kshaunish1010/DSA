#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // Returns the sum of bitwise OR of all pairs in the array
    long long int sumXOR(int arr[], int n)
    {
        long long sum = 0; // Initialize the sum

        // Iterate over each bit from the least significant bit to the most significant bit (32 bits in total)
        for (int i = 0; i < 32; i++)
        {
            long long countZero = 0; // Count of elements with a '0' bit at the current position
            long long countOne = 0;  // Count of elements with a '1' bit at the current position

            // Iterate through the array elements
            for (int j = 0; j < n; j++)
            {
                if (arr[j] % 2 == 0)
                {
                    countZero++; // Increment countZero if the current element has a '0' bit at the current position
                }
                else
                {
                    countOne++; // Increment countOne if the current element has a '1' bit at the current position
                }
                arr[j] /= 2; // Right-shift the current element to process the next bit
            }

            // Calculate the contribution to the sum for the current bit position
            sum += countZero * countOne * (1 << i);
        }

        return sum; // Return the final sum
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