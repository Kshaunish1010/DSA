#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// User function Template for C++
class Solution
{
public:
    int solve(int freq, int x, int n, vector<int> &v, vector<int> &w)
    {
        // cout<<x;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == x && w[i] != x)
                cnt++;
        }
        // cout<<freq<<":"<<cnt;
        if (freq + cnt >= n)
        {
            return n - freq;
        }
        return -1;
    }
    int minSwaps(int N, vector<int> A, vector<int> B)
    {
        int cnt = 0, candidate = 0;
        for (auto it : A)
        {
            if (cnt == 0)
            {
                candidate = it;
                cnt++;
            }
            else if (candidate == it)
                cnt++;
            else
                cnt--;
        }
        int freqA = 0;
        for (auto it : A)
        {
            if (candidate == it)
                freqA++;
        }
        int ans1 = solve(freqA, candidate, A.size(), B, A);
        // cout<<ans1;
        cnt = 0;
        candidate = 0;
        for (auto it : B)
        {
            if (cnt == 0)
            {
                candidate = it;
                cnt++;
            }
            else if (candidate == it)
                cnt++;
            else
                cnt--;
        }
        int freqB = 0;
        for (auto it : B)
        {
            if (candidate == it)
                freqB++;
        }
        int ans2 = solve(freqB, candidate, B.size(), A, B);
        if ((ans1 == -1 && ans2 != -1))
            return ans2;
        else if ((ans2 == -1 && ans1 != -1))
            return ans1;
        else
            return min(ans1, ans2);
        // return 0;
        //  code here
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