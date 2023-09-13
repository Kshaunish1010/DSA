#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        // code here
        int ans = -1, c = m - 1;
        for (int i = 0; i < m; i++)
        {
            if (arr[0][i] == 1)
            {
                c = i - 1;
                ans = 0;
                break;
            }
        }
        if (c + 1 == 0)
            return ans;
        for (int i = 1; i < n; i++)
        {
            if (arr[i][c] == 1)
            {
                while (c >= 0 && arr[i][c])
                {
                    c--;
                }
                ans = i;
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