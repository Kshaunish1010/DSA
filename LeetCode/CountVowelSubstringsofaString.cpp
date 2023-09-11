#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return 1;
        return 0;
    }
    int countVowelSubstrings(string word)
    {
        unordered_map<char, int> mp;
        int ans = 0;
        for (int i = 0; i < word.length(); i++)
        {
            mp.clear();
            for (int j = i; j < word.length() && isVowel(word[j]); j++)
            {
                mp[word[j]]++;
                if (mp.size() == 5)
                    ans++;
            }
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