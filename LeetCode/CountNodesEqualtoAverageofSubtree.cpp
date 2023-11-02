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
    int ans = 0;

    // Function to calculate the total sum and count of nodes in the subtree.
    pair<int, int> solve(TreeNode *root)
    {
        // Base case: If the node is null, return {0, 0}.
        if (!root)
            return {0, 0};

        // Recursively calculate the total sum and count for the left and right subtrees.
        auto p1 = solve(root->left);
        auto p2 = solve(root->right);

        // Calculate the total sum and total count for the current subtree.
        int totalSum = p1.first + p2.first + root->val;
        int totalCount = p1.second + p2.second + 1;

        // Calculate the average value for the current subtree.
        int avg = totalSum / totalCount;

        // Check if the current node's value equals the average value.
        if (root->val == avg)
            ans++;

        // Return the total sum and total count for the current subtree.
        return {totalSum, totalCount};
    }

    // Function to find the count of subtrees with nodes having values equal to their subtree averages.
    int averageOfSubtree(TreeNode *root)
    {
        // Call the solve function to traverse and calculate the count.
        solve(root);

        // Return the count of such subtrees.
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