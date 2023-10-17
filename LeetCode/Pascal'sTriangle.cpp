#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        ans.push_back({1});
        if (numRows == 1)
            return ans;
        ans.push_back({1, 1});
        for (int i = 3; i <= numRows; i++)
        {
            vector<int> v(i, 1);
            vector<int> temp = ans.back();
            for (int j = 1; j < i - 1; j++)
            {
                v[j] = temp[j - 1] + temp[j];
            }
            ans.push_back(v);
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