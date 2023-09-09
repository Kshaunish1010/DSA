#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    int ans = 0;
    int count = 0;
    void revinorder(Node *root, int k)
    {
        if (root == NULL)
            return;
        revinorder(root->right, k);
        count++;
        if (count == k)
        {
            ans = root->data;
            return;
        }
        revinorder(root->left, k);
    }
    int kthLargest(Node *root, int K)
    {
        revinorder(root, K);
        return ans;
        // Your code here
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