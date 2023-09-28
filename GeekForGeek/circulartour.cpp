#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int totalPetrol = 0, currPetrol = 0, start = 0;
        for (int i = 0; i < n; i++)
        {
            totalPetrol += p[i].petrol - p[i].distance;
            currPetrol += p[i].petrol - p[i].distance;
            if (currPetrol < 0)
            {
                currPetrol = 0;
                start = i + 1;
            }
        }
        return (totalPetrol >= 0) ? start : -1;
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