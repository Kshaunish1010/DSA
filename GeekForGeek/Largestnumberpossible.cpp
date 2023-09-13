#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string findLargest(int n, int s)
    {
        // code here
        if (n > 0 && s <= 0)
            return "-1";
        string ans = "";
        while (n > 0)
        {
            if (s >= 9)
            {
                ans += '9';
                s -= 9;
            }
            else
            {
                ans += char(s + '0');
                s -= s;
            }
            n--;
        }
        if (s == 0)
            return ans;
        return "-1";
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