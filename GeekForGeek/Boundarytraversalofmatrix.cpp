#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // Function to return a list of integers that form the boundary
    // traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int>> &matrix, int n, int m)
    {
        vector<int> ans;

        // Traverse the top row from left to right
        for (int j = 0; j < m; j++)
        {
            ans.push_back(matrix[0][j]);
        }

        // Traverse the rightmost column from top to bottom
        for (int i = 1; i < n; i++)
        {
            ans.push_back(matrix[i][m - 1]);
        }

        // If there is more than one row, traverse the bottom row from right to left
        if (n > 1)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                ans.push_back(matrix[n - 1][j]);
            }
        }

        // If there is more than one column, traverse the leftmost column from bottom to top
        if (m > 1)
        {
            for (int i = n - 2; i >= 1; i--)
            {
                ans.push_back(matrix[i][0]);
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