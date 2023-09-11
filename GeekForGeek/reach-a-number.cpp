#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    int reachNumber(int target)
    {
        long long int steps = 0, sum = 0;
        target = abs(target);
        while (sum < target)
        {
            sum += steps;
            steps++;
        }
        while ((sum - target) % 2 == 1)
        {
            sum += steps;
            steps++;
        }
        return steps - 1;
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