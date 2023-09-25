#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int n = s.length(), sum = 0;

        // Calculate the sum of ASCII values of characters in string s
        for (int i = 0; i < n; i++)
        {
            sum += s[i] - 'a' + 1;
        }

        int nsum = 0;
        // Calculate the sum of ASCII values of characters in string t
        for (int j = 0; j <= n; j++)
        {
            nsum += t[j] - 'a' + 1;
        }

        // Calculate the difference between the sums and convert it to the corresponding character
        char ans = nsum - sum + 'a' - 1;

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