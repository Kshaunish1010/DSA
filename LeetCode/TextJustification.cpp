#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<string> ans;
    void solve(int i, int j, vector<string> &words, int maxWidth)
    {
        int total = 0;
        for (int k = i; k <= j; k++)
        {
            total += words[k].size();
        }
        int x = j - i;
        int space = (maxWidth - total);
        string temp = "";
        int y = space / x;
        //even no. of spaces
        if (space % x == 0)
        {
            for (int k = i; k <= j; k++)
            {
                temp += words[k];
                int c = y;
                while (k != j && c > 0)
                {
                    temp += " ";
                    c--;
                }
            }
        }
        // for uneven no. of spaces
        else
        {
            int z = space % x;
            for (int k = i; k <= j; k++)
            {
                temp += words[k];
                int c = y;
                // if condition to even distribute the extra space on left side of line
                if (z > 0)
                {
                    temp += " ";
                    z--;
                }
                //the normal space calculated like in above if condition which can be evenly distributed
                while (k != j && c > 0)
                {
                    temp += " ";
                    c--;
                }
            }
        }
        cout << temp;
        ans.push_back(temp);
    }
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int i = 0, j = 0;
        int n = words.size();
        if (maxWidth == 1)
            return words;
        while (i < n && j < n)
        {
            int len = words[j].size();
            int cnt = len;
            while (j < n && cnt <= maxWidth)
            {
                if (cnt < maxWidth)
                    cnt += 1;
                j++;
                if (j >= n)
                    break;
                cnt += words[j].size();
            }
            cnt -= words[j].size();
            j--;
            //if word length equal to maxWidth
            if (i == j)
            {
                string temp = "";
                temp += words[j];
                int s = maxWidth - words[j].length();
                while (s > 0)
                {
                    temp += " ";
                    s--;
                }
                ans.push_back(temp);
            }
            //for last line
            else if (i < j && j == n - 1)
            {
                string temp = "";
                int total = 0, g = 0;
                for (int k = i; k <= j; k++)
                {
                    total += words[k].length();
                    temp += words[k];
                    if (total + g == maxWidth)
                        break;
                    temp += " ";
                    g++;
                }
                int s = maxWidth - total - g;
                while (s > 0)
                {
                    temp += " ";
                    s--;
                }
                ans.push_back(temp);
            }
            //for other lines
            else
                solve(i, j, words, maxWidth);
            j++;
            i = j;
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