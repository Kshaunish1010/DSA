#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    int solve(vector<int> &stores, int h)
    {
        int l = 0, r = stores.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (stores[mid] == h)
                return h;
            if (stores[mid] < h)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if (r < 0)
            return stores[l];
        if (l >= stores.size())
            return stores[r];
        int diff1 = abs(stores[l] - h);
        int diff2 = abs(stores[r] - h);
        if (diff1 < diff2)
        {
            return stores[l];
        }
        return stores[r];
    }
    vector<int> findStores(int n, vector<int> houses, int m, vector<int> stores)
    {
        sort(stores.begin(), stores.end());
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int house = houses[i];
            int closestStore = solve(stores, house);
            ans.push_back(closestStore);
        }
        return ans;
        // code here
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