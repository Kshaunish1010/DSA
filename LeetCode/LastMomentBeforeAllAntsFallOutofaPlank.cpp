#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int res = 0; // Initialize a variable to store the last moment

        // Loop through the positions in the 'left' vector
        for (int &i : left)
        {
            res = max(res, i); // Update 'res' with the maximum value from 'left'
        }

        // Loop through the positions in the 'right' vector
        for (int &i : right)
        {
            res = max(res, n - i); // Update 'res' with the maximum value from 'right'
        }

        return res; // Return the maximum of the two maximum values from 'left' and 'right'
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