#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    static int numberof1s(int a)
    {
        int count = 0;
        while (a)
        {
            a = a & (a - 1);
            count++;
        }
        return count;
    }
    static bool compare(int a, int b)
    {
        int p = numberof1s(a);
        int q = numberof1s(b);
        if (p == q)
        {
            return (a <= b);
        }
        else
        {
            return (p < q);
        }
    }
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);
        return arr;
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