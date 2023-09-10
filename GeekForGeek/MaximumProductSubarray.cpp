#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// User function template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        // code here
        long long ans = arr[0];
        long long max_ending = arr[0];
        long long min_ending = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < 0)
            {
                swap(max_ending, min_ending);
            }
            max_ending = max(max_ending * arr[i], static_cast<long long>(arr[i]));
            min_ending = min(min_ending * arr[i], static_cast<long long>(arr[i]));
            ans = max(max_ending, ans);
        }
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