#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int n;
    int solve(vector<vector<int>> &matrix, vector<vector<int>> &dp, int r, int c)
    {
        if (r == n - 1)
            return matrix[r][c];
        if (dp[r][c] != -1)
            return dp[r][c];
        int x = INT_MIN, y = INT_MIN, z = INT_MIN;
        if (r + 1 < n)
            x = matrix[r][c] + solve(matrix, dp, r + 1, c);
        if (r + 1 < n && c - 1 >= 0)
            y = matrix[r][c] + solve(matrix, dp, r + 1, c - 1);
        if (r + 1 < n && c + 1 < n)
            z = matrix[r][c] + solve(matrix, dp, r + 1, c + 1);
        return dp[r][c] = max({x, y, z});
    }
    int maximumPath(int N, vector<vector<int>> &matrix)
    {
        n = N;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, solve(matrix, dp, 0, i));
        }
        return ans;
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