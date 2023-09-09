#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    // Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n)
    {
        int max_id = n - 1;
        int min_id = 0;
        int max_element = arr[n - 1] + 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] += (arr[max_id] % max_element) * max_element;
                max_id--;
            }
            else
            {
                arr[i] += (arr[min_id] % max_element) * max_element;
                min_id++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] / max_element;
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