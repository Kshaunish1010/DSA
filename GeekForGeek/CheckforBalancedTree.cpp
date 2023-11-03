#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.

    // Recursive function to calculate the height of the tree.
    int solve(Node *root)
    {
        if (!root)
            return 0;

        // Recursively calculate the height of the left and right subtrees.
        int h1 = solve(root->left);
        int h2 = solve(root->right);

        // If any subtree is unbalanced or the height difference is greater than 1, return -1.
        if (h1 == -1 || h2 == -1 || abs(h1 - h2) > 1)
            return -1;

        // Return the height of the current subtree.
        return 1 + max(h1, h2);
    }

    // Main function to check if the tree is balanced.
    bool isBalanced(Node *root)
    {
        return solve(root) != -1; // If solve() returns -1, the tree is unbalanced.
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