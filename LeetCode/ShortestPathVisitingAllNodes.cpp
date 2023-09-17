#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// 1.mask:

// mask is an integer variable that is used to keep track of visited cities or nodes in the graph.
// Each bit in the mask represents whether a city has been visited or not. For example, if mask is 010110, it means that cities 1, 3, and 4 have been visited (since the corresponding bits are set to 1), and cities 0 and 2 haven't been visited (since the corresponding bits are 0).
// The mask helps to ensure that we visit each city exactly once and also keeps track of which cities have been visited in the current path.
// 2.s:

// s is an integer that represents a binary number with all bits set to 1. It's essentially a mask where all cities are visited.
// The value of s is calculated as (1 << n) - 1, where 'n' is the number of cities in the graph. This results in a binary number with 'n' trailing 1s, indicating that all cities are visited.
// The s mask is used to check whether we have visited all cities and can terminate the search when it's reached. If the mask becomes equal to s, it means we have visited all cities, and we return the result.
// Here's how these variables work together in the code:

// =>Initially, we start with all cities unvisited (mask is 0) and visit each city one by one in a loop.
// For each city visited, we push it into the queue along with the current distance traveled (d) and the updated mask to mark the city as visited.
// We use vis (a set) to keep track of visited states (city, mask) to avoid revisiting the same state multiple times.
// In the BFS loop, we explore all possible neighboring cities that can be visited from the current city while marking them as visited by updating the mask.
// If the mask becomes equal to s, it means we have visited all cities, and we return the distance (d + 1) as the shortest path length.
// The BFS continues until all possible paths have been explored, and if we don't find a solution, we return 0.
// So, mask helps to maintain the state of visited cities, and s is used as a target state to determine when all cities have been visited. Together, they are essential for finding the shortest path that visits all nodes.

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int s = (1 << n) - 1;
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> vis;
        for (int i = 0; i < n; i++)
        {
            int mask = 1 << i;
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first, d = it.second.first, mask = it.second.second;
            for (auto x : graph[node])
            {
                int newMask = mask | 1 << x;
                if (newMask == s)
                    return d + 1;
                else if (vis.count({x, newMask}))
                    continue;
                else
                {
                    q.push({x, {d + 1, newMask}});
                    vis.insert({x, newMask});
                }
            }
        }
        return 0;
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