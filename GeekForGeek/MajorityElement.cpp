#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// User function template for C++

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int n)
    {
        int cnt = 0;
        int candidate = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                candidate = a[i];
                cnt++;
            }
            else if (candidate == a[i])
                cnt++;
            else
                cnt--;
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (candidate == a[i])
                cnt++;
        }
        if (cnt > n / 2)
            return candidate;
        return -1;
        // your code here
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