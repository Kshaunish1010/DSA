#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// User function Template for C++

class Solution
{
public:
    int repeatNum(int arr[], int n)
    {
        // code here
        int cnt1 = 0, cnt2 = 0;
        int candidate1 = 0, candidate2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (candidate1 == arr[i])
            {
                cnt1++;
            }
            else if (candidate2 == arr[i])
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                candidate1 = arr[i];
                cnt1++;
            }
            else if (cnt2 == 0)
            {
                candidate2 = arr[i];
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == candidate1)
                cnt1++;
            if (arr[i] == candidate2)
                cnt2++;
        }
        if (cnt1 > n / 3 && cnt2 > n / 3)
            return min(candidate1, candidate2);
        else if (cnt1 > n / 3)
            return candidate1;
        else if (cnt2 > n / 3)
            return candidate2;
        else
            return -1;
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