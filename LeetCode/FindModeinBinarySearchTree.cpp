#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    unordered_map<int, int> mp;
    void solve(TreeNode *root)
    {
        if (root == NULL)
            return;
        solve(root->left);
        mp[root->val]++;
        solve(root->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        solve(root);
        vector<int> res;
        int cnt = INT_MIN;
        for (auto it : mp)
        {
            if (cnt < it.second)
            {
                cnt = it.second;
            }
        }
        for (auto it : mp)
        {
            if (cnt == it.second)
            {
                res.push_back(it.first);
            }
        }
        return res;
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