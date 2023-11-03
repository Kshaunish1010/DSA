#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    // Function to check if the Pythagorean triplet exists or not.
    bool checkTriplet(int arr[], int n)
    {
        // Sorting the array in ascending order to optimize the search.
        sort(arr, arr + n);

        // Loop through the array in reverse order starting from the largest element.
        for (int i = n - 1; i >= 2; i--)
        {
            int temp = arr[i] * arr[i]; // Calculate the square of the largest element.
            int low = 0;
            int high = i - 1;

            // Use a two-pointer approach to search for the other two elements.
            while (low < high)
            {
                int sum = arr[low] * arr[low] + arr[high] * arr[high];

                // If the sum of squares of two elements matches the square of the largest element, it's a Pythagorean triplet.
                if (sum == temp)
                    return true;
                if (sum < temp)
                    low++; // Increment the left pointer if the sum is smaller.
                else
                    high--; // Decrement the right pointer if the sum is larger.
            }
        }

        return false; // If no Pythagorean triplet is found, return false.
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