#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        unordered_map<string, int> mp;
        string s = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            s += strs[0][i];
            mp[s]++;
        }
        
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