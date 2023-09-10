#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    int maxDistance(vector<int> A, int n)
    {
        int prevPerson = -1;
        int maxDist = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i])
            {
                if (prevPerson == -1)
                {
                    maxDist = max(i, maxDist);
                }
                else
                {
                    maxDist = max(maxDist, (i - prevPerson) / 2);
                }
                prevPerson = i;
            }
        }
        if (maxDist < n - 1 - prevPerson)
            maxDist = n - 1 - prevPerson;
        return maxDist;
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