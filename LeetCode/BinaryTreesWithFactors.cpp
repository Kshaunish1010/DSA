#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int MOD = 1e9 + 7;

    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        sort(begin(arr), end(arr)); // Sort the input array in ascending order.

        unordered_map<int, long long> mp;
        mp[arr[0]] = 1; // Initialize the map with the first element.

        for (int i = 1; i < n; i++)
        {
            long long count = 1; // Initialize the count for the current element.

            for (int j = 0; j < i; j++)
            {
                int v = arr[j];
                if (arr[i] % v == 0 && mp.find(arr[i] / v) != mp.end())
                {
                    // If arr[i] is divisible by v and arr[i] / v is present in the map:
                    // Calculate the count based on the product of counts for v and arr[i] / v.
                    count += (mp[v] * mp[arr[i] / v]);
                }
            }

            mp[arr[i]] = count; // Store the count in the map for the current element.
        }

        int result = 0;
        for (auto &it : mp)
        {
            result = (result + it.second) % MOD; // Calculate the final result by summing up all counts.
        }
        return result;
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