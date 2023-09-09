#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// User function Template for C++

class Solution
{
public:
    vector<int> printMissingIntervals(int a[], int n)
    {
        // code here
        vector<int> ans;
        int k = 0;
        for (int i = 0; i < 99999 && k < n; i++)
        {
            if (i != a[k])
            {
                ans.push_back(i);
                ans.push_back(a[k] - 1);
                i = a[k];
            }
            k++;
        }
        if (a[n - 1] != 99999)
        {
            ans.push_back(a[n - 1] + 1);
            ans.push_back(99999);
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