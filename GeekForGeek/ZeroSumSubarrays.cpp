#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// User function template for C++

class Solution
{
public:
    // Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n)
    {
        // code here
        unordered_map<long long int, long long int> mp;
        long long int sum = 0, cnt = 0;
        for (auto it : arr)
        {
            sum += it;
            if (sum == 0)
                cnt++;
            if (mp.find(sum) != mp.end())
                cnt += mp[sum];
            mp[sum]++;
        }
        return cnt;
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