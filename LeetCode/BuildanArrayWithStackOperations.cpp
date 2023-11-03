#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int stream = 1, i = 0;
        vector<string> ans;

        // Iterate through the elements in the "target" array.
        while ((i < target.size()) && stream <= n)
        {
            ans.push_back("Push"); // Always push the current value to the result.

            // If the current value in "target" doesn't match the current "stream" value,
            // add a "Pop" operation to the result. Otherwise, move to the next index in "target".
            if (target[i] != stream)
            {
                ans.push_back("Pop");
            }
            else
            {
                i++;
            }

            stream++; // Move to the next value in the "stream."
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