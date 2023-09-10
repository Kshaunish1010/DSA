#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// User function template for C++
class Solution
{
public:
    vector<int> findSubarray(int a[], int n)
    {
        // code here
        int i = 0, j = 0, sum = 0, start = 0, end = 0;
        while (i < n && a[i] < 0)
            i++;
        sum += a[i];
        j = i + 1;
        int maxi = INT_MIN;
        while (j < n)
        {
            if (a[j] >= 0)
            {
                sum += a[j];
                j++;
            }
            else if (a[j] < 0)
            {
                if (maxi < sum)
                {
                    start = i;
                    end = j;
                    maxi = sum;
                }
                else if (maxi == sum)
                {
                    if (end - start < j - i)
                    {
                        start = i;
                        end = j;
                    }
                }
                sum = 0;
                j++;
                i = j;
            }
        }
        if (sum >= maxi)
        {
            if (maxi == sum)
            {
                if (end - start < j - i)
                {
                    start = i;
                    end = j;
                }
            }
            else
            {
                start = i;
                end = j;
            }
        }
        vector<int> ans;
        for (i = start; i < end; i++)
        {
            ans.push_back(a[i]);
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