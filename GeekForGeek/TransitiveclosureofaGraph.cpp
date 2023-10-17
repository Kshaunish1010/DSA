#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    // Depth-First Search (DFS) function to mark the transitive closure between nodes.
    void dfs(vector<vector<int>> &res, vector<vector<int>> &adj, int node, int i) {
        for (auto it : adj[i]) {
            if (res[node][it] == 0) { // Check if this connection hasn't been marked yet.
                res[node][it] = 1; // Mark the connection between node and its reachable nodes.
                dfs(res, adj, node, it); // Continue the DFS traversal from the reachable node.
            }
        }
    }

    // Function to compute the transitive closure of a directed graph.
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph) {
        // Create an adjacency list to represent the directed graph.
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && graph[i][j]) {
                    adj[i].push_back(j); // Add reachable nodes to the adjacency list.
                }
            }
        }

        // Initialize the result matrix with zeros, and set diagonal to 1.
        vector<vector<int>> res(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            res[i][i] = 1; // There is always a path from a node to itself.
            dfs(res, adj, i, i); // Mark the transitive closure for each node.
        }

        return res; // Return the transitive closure matrix.
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