#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct Node
{
    int data;
    Node *right;
    Node *left;

    Node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};

class Solution
{
public:
    // Recursive function to find the floor value in the BST.
    void solve(Node *root, int x, int &ans)
    {
        if (root == NULL)
            return; // Base case: If the node is NULL, return.

        if (root->data <= x)
        {
            // If the current node's data is less than or equal to 'x', update 'ans' with the maximum of current data.
            ans = max(ans, root->data);

            // Continue searching in the right subtree for a larger floor value.
            solve(root->right, x, ans);
        }
        else
        {
            // If the current node's data is greater than 'x', no need to consider the right subtree.
            // Continue searching in the left subtree for a potential floor value.
            solve(root->left, x, ans);
        }
    }

    // Main function to find the floor value in the BST.
    int floor(Node *root, int x)
    {
        int ans = -1;        // Initialize 'ans' to -1 as the initial floor value.
        solve(root, x, ans); // Call the recursive function to find the floor value.
        return ans;          // Return the final floor value.
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