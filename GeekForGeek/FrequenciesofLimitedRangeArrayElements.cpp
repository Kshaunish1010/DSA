#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int> &arr, int N, int P)
    {
        // First, we need to handle elements greater than N by setting them to 0.
        for (int i = 0; i < N; i++)
        {
            if (arr[i] > N)
                arr[i] = 0;
        }

        // Now, we use an efficient method to count frequencies and modify the array.
        for (int i = 0; i < N; i++)
        {
            if (arr[i] % (N + 1) > 0)
                arr[(arr[i] % (N + 1)) - 1] += (N + 1);
        }

        // Finally, we restore the original values by dividing them by (N + 1).
        for (int i = 0; i < N; i++)
        {
            arr[i] /= (N + 1);
        }
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