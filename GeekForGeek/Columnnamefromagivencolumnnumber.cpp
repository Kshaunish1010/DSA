#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string colName(long long int n)
    {
        if (n < 27)
            return string(1, 'A' + (n - 1) % 26);
        string s = "";
        while (n > 0)
        {
            if (n % 26 == 0)
            {
                s += 'A' + 25;
                n -= 1;
            }
            else
            {
                s += 'A' + (n - 1) % 26;
            }
            n = n / 26;
        }
        reverse(s.begin(), s.end());
        return s;
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