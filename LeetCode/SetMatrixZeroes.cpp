#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// extra space
// class Solution
// {
// public:
//     void setZeroes(vector<vector<int>> &matrix)
//     {
//         set<int> srow;
//         set<int> scol;
//         int n = matrix.size();
//         int m = matrix[0].size();
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (matrix[i][j] == 0)
//                 {
//                     srow.insert(i);
//                     scol.insert(j);
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (srow.count(i) > 0 || scol.count(j) > 0)
//                 {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };

// optimised approach
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        bool flagR = false, flagC = false;

        // Step 1: Identify if first row and column need to be zeroed out
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
                flagC = true; // Flag for column
        }
        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] == 0)
                flagR = true; // Flag for row
        }

        // Step 2: Use the first row and first column as markers to store zero information
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // Mark the corresponding row in the first column
                    matrix[0][j] = 0; // Mark the corresponding column in the first row
                }
            }
        }

        // Step 3: Zero out rows and columns based on the markers
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0; // Zero out cells based on the markers
                }
            }
        }

        // Step 4: Zero out the first column if needed
        if (flagC)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }

        // Step 5: Zero out the first row if needed
        if (flagR)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[0][i] = 0;
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