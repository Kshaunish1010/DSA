#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> vi(rowIndex + 1); // Create a vector to store the elements of the rowIndex-th row.
        vi[0] = 1;                    // Initialize the first element to 1 as it is always 1 in Pascal's triangle.

        for (int i = 0; i <= rowIndex; ++i)
        {
            for (int j = i; j > 0; --j)
            {
                vi[j] = vi[j] + vi[j - 1]; // Calculate each element based on the values of the previous row.
            }
        }

        return vi; // Return the vector representing the rowIndex-th row of Pascal's triangle.
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