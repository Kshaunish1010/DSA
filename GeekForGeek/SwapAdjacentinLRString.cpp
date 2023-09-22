#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    bool canTransform(string S, string T) {
        int i = 0, j = 0, n = S.size();
        
        // Iterate through the strings while comparing characters.
        while (i < n || j < n) {
            // Skip 'X' characters in both strings.
            while (S[i] == 'X') i++;
            while (T[j] == 'X') j++;
            
            // If characters at positions i and j are not equal, return false.
            if (S[i] != T[j]) return false;
            
            // Check for conditions where 'R' cannot move to the left or 'L' cannot move to the right.
            if (S[i] == 'R' && i > j) return false;
            if (S[i] == 'L' && i < j) return false;
            
            // Move the pointers to the next positions.
            i++, j++;
        }
        
        // If the loop completes, a valid transformation is possible, so return true.
        return true;
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