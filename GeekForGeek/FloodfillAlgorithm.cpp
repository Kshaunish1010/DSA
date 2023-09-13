#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int dr[] = {-1, 0, +1, 0};
int dc[] = {0, +1, 0, -1};

class Solution
{
public:
    int n, m, srcColor;

    bool isValid(int i, int j, vector<vector<int>> &vis)
    {
        return (i < n && j < m && i >= 0 && j >= 0 && !(vis[i][j]));
    }

    void dfs(vector<vector<int>> &image, vector<vector<int>> &vis, int r, int c, int color)
    {
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (isValid(nr, nc, vis) && image[nr][nc] == srcColor)
            {
                image[nr][nc] = color;
                vis[nr][nc] = 1;
                dfs(image, vis, nr, nc, color);
            }
        }
    }
    vector<vector<int>>
    floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here
        n = image.size();
        m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sr][sc] = 1;
        srcColor = image[sr][sc];
        image[sr][sc] = newColor;
        dfs(image, vis, sr, sc, newColor);
        return image;
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