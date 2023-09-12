#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int n, m;
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        return (i < n && j < m && i >= 0 && j >= 0 && grid[i][j] == 1);
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        queue<pair<pair<int, int>, int>> q;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[source.first][source.second] = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        q.push({source, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int d = it.second;
            if (x == destination.first && y == destination.second)
            {
                return d;
            }
            for (int i = 0; i < 4; i++)
            {
                int nr = x + dr[i];
                int nc = y + dc[i];
                if (isValid(nr, nc, grid) && 1 + d < dist[nr][nc])
                {
                    dist[nr][nc] = 1 + d;
                    q.push({{nr, nc}, d + 1});
                }
            }
        }
        return -1;
        // code here
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