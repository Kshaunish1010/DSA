#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0}); // {effort, row, column}

        while (!pq.empty())
        {
            auto [effort, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == m - 1)
            {
                return effort;
            }

            if (effort >= efforts[r][c])
            {
                continue;
            }

            efforts[r][c] = effort;

            for (auto &dir : dirs)
            {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    int newEffort = max(effort, abs(heights[nr][nc] - heights[r][c]));
                    pq.push({newEffort, nr, nc});
                }
            }
        }

        return 0; // This should never be reached if there is a valid path.
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