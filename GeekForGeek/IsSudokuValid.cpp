#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    bool check(vector<vector<int>> &mat, int i, int j, int ch)
    {
        for (int k = 0; k < 9; k++)
        {
            // for row
            if (mat[i][k] == ch)
                return false;

            // for col
            if (mat[k][j] == ch)
                return false;

            if (mat[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == ch)
                return false;
        }

        return true;
    }

    int isValid(vector<vector<int>> mat)
    {

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (mat[i][j] != 0)
                {
                    int val = mat[i][j];
                    mat[i][j] = 0;
                    if (check(mat, i, j, val))
                        mat[i][j] = val;
                    else
                        return 0;
                }
            }
        }

        return 1;
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