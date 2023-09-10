#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        int ind = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                ind = i;
                break;
            }

            int find = n - 1;
            int y = INT_MAX;
            for (int i = n - 1; i > ind; i--)
            {
                if (arr[i] > arr[ind])
                {
                    if (y > arr[i])
                    {
                        y = arr[i];
                        find = i;
                    }
                }
            }
            swap(arr[find], arr[ind]);
            sort(arr.begin() + ind + 1, arr.end());
            return arr;
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