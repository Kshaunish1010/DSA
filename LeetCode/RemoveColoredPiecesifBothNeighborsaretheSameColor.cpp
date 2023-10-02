#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    // Function to determine the winner of the game based on the given colors.
    bool winnerOfGame(string colors)
    {
        int a = 0, b = 0; // Initialize counts for player A and player B.

        // Loop through the colors, starting from the second position and ending
        // at the second-to-last position to check for consecutive triples.
        for (int i = 1; i < colors.size() - 1; i++)
        {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
            {
                // If there is a consecutive triple of the same color, increment
                // the count for the respective player (A or B).
                if (colors[i] == 'A')
                    a++;
                else
                    b++;
            }
        }

        // Return true if player A has more consecutive triples, indicating the winner.
        return a > b;
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