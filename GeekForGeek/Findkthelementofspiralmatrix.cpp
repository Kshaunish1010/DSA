#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define MAX 1000

class Solution
{
public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX], int n, int m, int k)
    {
        int l = 0, r = m - 1, t = 0, b = n - 1;
        int cnt = 0;
        while (t <= r && t <= b)
        {
            for (int i = l; i <= r; i++)
            {
                cnt++;
                if (cnt == k)
                    return a[t][i];
            }
            t++;
            for (int i = t; i <= b; i++)
            {
                cnt++;
                if (cnt == k)
                    return a[i][r];
            }
            r--;
            for (int i = r; i >= l; i--)
            {
                cnt++;
                if (cnt == k)
                    return a[b][i];
            }
            b--;
            for (int i = b; i >= t; i--)
            {
                cnt++;
                if (cnt == k)
                    return a[i][l];
            }
            l++;
        }
        return -1;
        // Your code goes here.
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