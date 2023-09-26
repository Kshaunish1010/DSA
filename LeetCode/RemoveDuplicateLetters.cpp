#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, -1); // Initialize lastIndex with -1
        int n = s.length();
        for (int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        string ans;
        vector<bool> v(26, false);
        for (int i = 0; i < n; i++) {
            if (v[s[i] - 'a']) {
                continue; // Skip if the character is already in the result
            }
            
            // If the current character is smaller than the last character in ans
            // and the last character will appear later in the string, remove it.
            while (!ans.empty() && s[i] < ans.back() && i < lastIndex[ans.back() - 'a']) {
                v[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            ans.push_back(s[i]);
            v[s[i] - 'a'] = true;
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