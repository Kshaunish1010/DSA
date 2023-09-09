#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<vector<int>> ans;
    int n;
    void solve(vector<int> &v, int i, int target, vector<int> temp)
    {
        if (i == n)
            return;
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (v[i] <= target)
        {
            temp.push_back(v[i]);
            solve(v, i, target - v[i], temp);
            temp.pop_back();
        }
        solve(v, i + 1, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        n = candidates.size();
        ans.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, 0, target, temp);
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