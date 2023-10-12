#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

class Solution
{
public:
    /* This function returns true if the tree contains
       a duplicate subtree of size 2 or more else returns false */
    string solve(Node *root, unordered_map<string, int> &mp)
    {
        if (root == nullptr)
            return ""; // Return an empty string to represent null nodes in the tree.

        // Serialize the subtree rooted at 'root'.
        string s = to_string(root->data) + solve(root->left, mp) + solve(root->right, mp);

        mp[s]++; // Update the counts of serialized subtrees.

        return s; // Return the serialized string for the current subtree.
    }

    int dupSub(Node *root)
    {
        unordered_map<string, int> mp;
        solve(root, mp); // Serialize the subtrees and populate the 'mp' map.

        // Iterate through the map to check for duplicate subtrees of size 2 or more.
        for (auto it : mp)
        {
            if (it.first.size() > 1 && it.second > 1)
            {
                return 1; // Return 1 if a duplicate subtree of size 2 or more is found.
            }
        }

        return 0; // Return 0 if no such duplicate subtree is found.
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