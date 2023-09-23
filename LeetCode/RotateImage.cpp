#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // Reverse the matrix upside down.
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();

        // Iterate through the lower triangular part of the matrix.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                // Swap the elements between the current cell and its symmetric counterpart.
                swap(matrix[i][j], matrix[j][i]);
            }
        }
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