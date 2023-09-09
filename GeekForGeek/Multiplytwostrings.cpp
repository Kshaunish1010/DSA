#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        bool isNegative = false;

        if (s1[0] == '-')
        {
            isNegative = !isNegative;
            s1 = s1.substr(1);
            n1--;
        }
        if (s2[0] == '-')
        {
            isNegative = !isNegative;
            s2 = s2.substr(1);
            n2--;
        }

        vector<int> result(n1 + n2, 0);

        for (int i = n2 - 1; i >= 0; i--)
        {
            int num2 = s2[i] - '0';
            for (int j = n1 - 1; j >= 0; j--)
            {
                int num1 = s1[j] - '0';
                int product = num1 * num2 + result[i + j + 1];
                result[i + j + 1] = product % 10;
                result[i + j] += product / 10;
            }
        }

        int start = 0;
        while (start < n1 + n2 && result[start] == 0)
        {
            start++;
        }

        if (start == n1 + n2)
        {
            return "0";
        }

        string finalResult;
        if (isNegative)
        {
            finalResult = "-";
        }
        for (int i = start; i < n1 + n2; i++)
        {
            finalResult += to_string(result[i]);
        }

        return finalResult;
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