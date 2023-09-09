#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long
class Solution
{
public:
    ll cnt = 0;
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(ll arr[], ll l, ll m, ll r)
    {
        ll i = l, j = m + 1;
        vector<ll> v;
        while (i <= m && j <= r)
        {
            if (arr[i] <= arr[j])
            {
                v.push_back(arr[i]);
                i++;
            }
            else
            {
                cnt += m - i + 1;
                v.push_back(arr[j]);
                j++;
            }
        }
        while (i <= m)
        {
            v.push_back(arr[i]);
            i++;
        }

        while (j <= r)
        {
            v.push_back(arr[j]);
            j++;
        }
        for (i = l; i <= r; i++)
        {
            arr[i] = v[i - l];
        }
    }
    void mergeSort(ll arr[], ll l, ll r)
    {
        if (l < r)
        {
            ll mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
    ll int inversionCount(ll arr[], ll N)
    {
        mergeSort(arr, 0, N - 1);
        return cnt;
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