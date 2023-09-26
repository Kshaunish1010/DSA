#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++)
        {
            // Avoid duplicate quadruples
            if (i > 0 && arr[i] == arr[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++)
            {
                // Avoid duplicate quadruples
                if (j > i + 1 && arr[j] == arr[j - 1])
                    continue;

                int l = j + 1;
                int r = n - 1;

                while (l < r)
                {
                    int sum = arr[i] + arr[j] + arr[l] + arr[r];
                    if (sum == k)
                    {
                        ans.push_back({arr[i], arr[j], arr[l], arr[r]});
                        // Move the left pointer and avoid duplicates
                        l++;
                        while (l < r && arr[l] == arr[l - 1])
                            l++;
                        // Move the right pointer and avoid duplicates
                        r--;
                        while (l < r && arr[r] == arr[r + 1])
                            r--;
                    }
                    else if (sum < k)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
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