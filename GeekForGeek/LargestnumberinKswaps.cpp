#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // Function to find the largest number after k swaps.
    int n;
    void solve(string str, int k, int i, string &ans)
    {
        if (i == n || k == 0)
        {
            ans = max(str, ans);
            return;
        }
        solve(str, k, i + 1, ans);
        for (int j = i + 1; j < n; j++)
        {
            if (str[j] > str[i])
            {
                swap(str[i], str[j]);
                solve(str, k - 1, i + 1, ans);
                swap(str[i], str[j]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        n = str.length();
        string ans = "";
        solve(str, k, 0, ans);
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