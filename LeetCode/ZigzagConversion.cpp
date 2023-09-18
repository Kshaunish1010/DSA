#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string ans = "";
        for (int i = 0; i < numRows; i++)
        {
            int nextindex = (numRows - 1) * 2;
            for (int j = i; j < s.size(); j += nextindex)
            {
                ans += s[j];
                int temp = j + nextindex - 2 * i;
                if (i != 0 && i != numRows - 1 && temp < s.size())
                {
                    ans += s[temp];
                }
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