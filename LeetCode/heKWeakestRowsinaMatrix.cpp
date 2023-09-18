#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j])
                    cnt++;
            }
            pq.push({cnt, i});
        }
        vector<int> ans;
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
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