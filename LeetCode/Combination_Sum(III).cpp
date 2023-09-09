#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<vector<int>> ans;
    void solve(int ind, int k, int n, vector<int> &temp)
    {
        if (temp.size() == k)
        {
            if (n == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        for (int i = ind; i < 10; i++)
        {
            if (i > n)
                break;
            temp.push_back(i);
            solve(i + 1, k, n - i, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> temp;
        solve(1, k, n, temp);
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