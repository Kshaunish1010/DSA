#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int x)
    {
        queue<pair<int, int>> q;   // Create a queue to perform BFS.
        vector<int> visited(V, 0); // Initialize a visited array to keep track of visited nodes.
        visited[0] = 1;            // Mark the starting node as visited.
        q.push({0, 0});            // Push the starting node (0) along with its level (0) into the queue.

        while (!q.empty())
        {
            int node = q.front().first;   // Get the node from the front of the queue.
            int level = q.front().second; // Get the level of the node.
            q.pop();                      // Remove the node from the queue.

            if (node == x) // If the current node matches the target node (x), return its level.
                return level;

            for (auto neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    q.push({neighbor, level + 1}); // Push unvisited neighbors into the queue with an increased level.
                    visited[neighbor] = 1;         // Mark the neighbor as visited.
                }
            }
        }
        return -1; // If the target node is not found, return -1.
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