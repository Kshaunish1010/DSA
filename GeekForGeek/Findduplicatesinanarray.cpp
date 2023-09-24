#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if ((arr[arr[i] % n] / n) < 2)
            {
                arr[arr[i] % n] = n + arr[arr[i] % n];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] / n >= 2)
            {
                ans.push_back(i);
            }
        }
        if (ans.empty())
        {
            ans.push_back(-1);
        }

        return ans;
        // code here
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