#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild) {
        // Create an adjacency list to represent the tree's edges.
        unordered_map<int, vector<int>> adj;
        // Create a mapping from child to parent nodes for validation.
        unordered_map<int, int> childToParent;
        
        // Iterate through the nodes and their left and right children.
        for (int i = 0; i < n; i++) {
            int node = i;
            int leftNode = leftChild[i];
            int rightNode = rightChild[i];
            
            // If a left child exists:
            if (leftNode != -1) {
                // Check if the left child already has a parent.
                if (childToParent.find(leftNode) != childToParent.end()) {
                    return false; // A child should have only one parent.
                }
                // Add the left child to the adjacency list and update the childToParent mapping.
                adj[node].push_back(leftNode);
                childToParent[leftNode] = i;
            }
            
            // If a right child exists:
            if (rightNode != -1) {
                // Check if the right child already has a parent.
                if (childToParent.find(rightNode) != childToParent.end()) {
                    return false; // A child should have only one parent.
                }
                // Add the right child to the adjacency list and update the childToParent mapping.
                adj[node].push_back(rightNode);
                childToParent[rightNode] = i;
            }
        }
        
        int root = -1;
        for (int i = 0; i < n; i++) {
            // Find the root node (a node with no parent).
            if (childToParent.find(i) == childToParent.end()) {
                if (root != -1) {
                    return false; // Multiple roots are not allowed.
                }
                root = i;
            }
        }
        
        // If there's no root, return false as there's no tree.
        if (root == -1) {
            return false;
        }
        
        // Validate that the tree is connected using a breadth-first search.
        queue<int> q;
        q.push(root);
        int cnt = 1; // Counter to track the number of nodes.
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                q.push(it);
                cnt++;
            }
        }
        
        // Return true if the tree is connected (all nodes are reachable).
        return cnt == n;
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