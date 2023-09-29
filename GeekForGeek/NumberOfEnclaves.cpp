#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

class Solution
{
public:
    int n, m;

    // DFS function to check if a land cell can walk off the boundary
    bool dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid, int &count)
    {
        if (r < 0 || c < 0 || r >= n || c >= m)
            return false; // We walked off the boundary.
        if (vis[r][c] || grid[r][c] == 0)
            return true; // This cell is visited or it's water, so it's safe.
        
        vis[r][c] = 1; // Mark it as visited.
        count += 1; // Increment the count of connected land cells.

        bool canWalkOffBoundary = true;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            canWalkOffBoundary &= dfs(nr, nc, vis, grid, count);
        }

        return canWalkOffBoundary;
    }

    // Main function to count the number of land cells that cannot walk off the boundary
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0; // Counter for land cells that cannot walk off the boundary
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array to track visited cells

        // Traverse each land cell and check if it can walk off the boundary.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int count = 0; // Counter for connected land cells
                if (!vis[i][j] && grid[i][j] && dfs(i, j, vis, grid, count))
                {
                    cnt += count;
                }
            }
        }

        return cnt;
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