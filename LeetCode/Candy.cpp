#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> v(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                v[i] = v[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i + 1] < ratings[i])
            {
                if (v[i] <= v[i + 1]);
                    v[i] = v[i + 1] + 1;
            }
        }
        int cnt = 0;
        for (auto it : v)
        {
            cnt += it;
        }
        return cnt;
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