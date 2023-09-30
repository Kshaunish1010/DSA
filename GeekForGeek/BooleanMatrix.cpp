#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    // void booleanMatrix(vector<vector<int>> &matrix)
    // {
    //     queue<pair<int, int>> q;
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < m; j++)
    //         {
    //             if (matrix[i][j])
    //                 q.push({i, j});
    //         }
    //     }
    //     while (!q.empty())
    //     {
    //         auto it = q.front();
    //         q.pop();
    //         for (int i = 0; i < n; i++)
    //         {
    //             matrix[i][it.second] = 1;
    //         }
    //         for (int i = 0; i < m; i++)
    //         {
    //             matrix[it.first][i] = 1;
    //         }
    //     }
    //     // code here
    // }
    void booleanMatrix(vector<vector<int>> &matrix)
    {
        bool flag1 = false;
        bool flag2 = false;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0])
                flag1 = true;
        }
        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i])
                flag2 = true;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j])
                {
                    matrix[i][0] = matrix[0][j] = 1;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] || matrix[0][j])
                {
                    matrix[i][j] = 1;
                }
            }
        }
        if (flag1)
        {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 1;
        }
        if (flag2)
        {
            for (int i = 0; i < m; i++)
                matrix[0][i] = 1;
        }
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