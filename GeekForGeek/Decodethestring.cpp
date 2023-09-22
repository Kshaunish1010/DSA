#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    string decodedString(string str)
    {

        stack<char> s;
        for (int i = str.size() - 1; i >= 0; i--)
        {

            if (str[i] != '[')
            {
                s.push(str[i]);
            }
            else
            {
                string temp = "";
                while (s.top() != ']')
                {
                    temp += s.top();
                    s.pop();
                }
                s.pop();
                i--;

                string tim = "";
                while (i >= 0 && str[i] <= '9')
                {
                    tim = str[i] + tim;
                    i--;
                }
                int times = stoi(tim);

                string temp2 = temp;
                while (times > 1)
                {
                    temp = temp2 + temp;
                    times--;
                }

                for (int i = temp.size() - 1; i >= 0; i--)
                    s.push(temp[i]);

                i++;
            }
        }

        string ans = "";
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
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