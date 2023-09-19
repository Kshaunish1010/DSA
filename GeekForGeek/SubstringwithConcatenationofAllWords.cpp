#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans; // Initialize a vector to store the indices of valid substrings.
        int totalword = words.size(); // Get the total number of words in the input vector.
        int length = words[0].length(); // Get the length of each word (assuming all words have the same length).
        int wordLength = length * totalword; // Calculate the total length of words combined.
        int sLength = s.length(); // Get the length of the input string.

        // If the input string is shorter than the total length of words, return an empty result.
        if (sLength < wordLength)
            return ans;

        unordered_map<string, int> mp;

        // Populate the unordered_map 'mp' with words and their counts from the input vector.
        for (const string& word : words) {
            mp[word]++;
        }

        // Loop through all possible starting positions of a valid substring.
        for (int i = 0; i < length; i++) {
            int left = i; // Initialize the left boundary of the current window.
            int count = 0; // Initialize the count of words in the current window.
            unordered_map<string, int> smp; // Initialize a map to store words and their counts in the current window.

            // Loop through the string with a step of 'length'.
            for (int j = i; j <= sLength - length; j += length) {
                string t = s.substr(j, length); // Get the current word from the string.
                
                if (mp.count(t)) {
                    smp[t]++; // Increment the count of the current word in the current window.
                    count++; // Increment the total count of words in the current window.

                    // If the count of the current word in the window exceeds its count in 'mp', adjust the window.
                    while (smp[t] > mp[t]) {
                        string leftWord = s.substr(left, length); // Get the leftmost word in the window.
                        smp[leftWord]--; // Decrement its count in the current window.
                        count--; // Decrement the total count of words in the window.
                        left += length; // Move the left boundary to the right to shrink the window.
                    }

                    // If all words are found in the current window, store the left index in 'ans'.
                    if (count == totalword) {
                        ans.push_back(left);
                        string leftWord = s.substr(left, length); // Get the leftmost word in the window.
                        smp[leftWord]--; // Decrement its count in the current window.
                        count--; // Decrement the total count of words in the window.
                        left += length; // Move the left boundary to the right to continue searching.
                    }
                } else {
                    // If the current word is not in 'mp', reset the window and counts.
                    smp.clear();
                    count = 0;
                    left = j + length;
                }
            }
        }

        return ans; // Return the vector of valid substring indices.
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