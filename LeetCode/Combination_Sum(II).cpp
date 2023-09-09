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
    void solve(vector<int> v, int target, int ind, vector<int> temp)
    {
        if (ind == n)
            return;
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < n; i++)
        {
            if (i > ind && v[i] == v[i - 1])
                continue;
            if (v[i] > target)
                break;
            temp.push_back(v[i]);
            solve(v, target - v[i], i + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        n = candidates.size();
        vector<int> temp;
        ans.clear();
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, temp);
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