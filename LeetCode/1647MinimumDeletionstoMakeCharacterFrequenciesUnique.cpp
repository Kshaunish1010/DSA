#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> v(26, 0);
        priority_queue<int> pq;
        for (auto it : s)
            v[it - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            if (v[i] == 0)
                continue;
            pq.push(v[i]);
        }
        int cnt = 0;
        while (!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            if (!pq.empty())
            {
                int y = pq.top();
                if (x != 0 && x == y)
                {
                    int i = x;
                    i--;
                    cnt++;
                    pq.push(i);
                }
            }
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