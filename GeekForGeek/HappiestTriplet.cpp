#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> smallestDifferenceTriplet(int arr1[], int arr2[], int arr3[], int n)
    {
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + n);
        sort(arr3, arr3 + n);
        int diff = INT_MAX;
        vector<int> ans;
        int i = 0, j = 0, k = 0;
        while (i < n && j < n && k < n)
        {
            int maxi = max(arr1[i], arr2[j], arr3[k]);
            int mini = min(arr1[i], arr2[j], arr3[k]);
            if (diff > maxi - mini)
            {
                diff = mini;
                ans = {arr1[i], arr2[j], arr3[k]};
            }
            if (mini == arr1[i])
            {
                i++;
            }
            if (mini == arr2[j])
            {
                j++;
            }
            if (mini == arr3[k])
            {
                k++;
            }
        }
        return ans;
        // code here.
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