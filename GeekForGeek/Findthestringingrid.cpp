#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
    string word;
    vector<vector<char>> grid;
    vector<vector<int>> ans;
    int n, m;
    vector<int> dx = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> dy = {0, 1, 1, 1, 0, -1, -1, -1};

public:
    bool isValid(int x, int y)
    {
        if (x < 0 || y < 0 || x >= n || y >= m)
            return false;
        return true;
    }
    bool kfs(int i, int j, int k, int prevDir = -1)
    {
        if (k == word.length())
            return true;

        if (!isValid(i, j))
            return false;

        bool val = false;
        if (word[k] == grid[i][j])
        {
            if (prevDir == -1)
            {
                for (int a = 0; a < 8; ++a)
                {
                    val |= kfs(i + dx[a], j + dy[a], k + 1, a);
                }
            }
            else
            {
                val |= kfs(i + dx[prevDir], j + dy[prevDir], k + 1, prevDir);
            }
        }
        if (val && prevDir == -1)
        {
            ans.push_back({i, j});
        }
        return val;
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        // Code here
        this->word = word;
        this->grid = grid;
        this->n = grid.size();
        this->m = grid[0].size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (word[0] == grid[i][j])
                {
                    kfs(i, j, 0);
                }
            }
        }
        return ans;
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