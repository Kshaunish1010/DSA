#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
class Solution
{
public:
    void merge(vector<int> &ans, vector<pair<int, int>> &v, int l, int mid, int h)
    {
        vector<pair<int, int>> temp;
        int i = l, j = mid + 1;
        int k;
        while (i <= mid && j <= h)
        {
            if (v[i].first <= v[j].first)
            {
                temp.push_back(v[j]);
                j++;
            }
            else
            {
                ans[v[i].second] += h - j + 1;
                temp.push_back(v[i]);
                i++;
            }
        }
        while (i <= mid)
        {
            temp.push_back(v[i]);
            i++;
        }
        while (j <= h)
        {
            temp.push_back(v[j]);
            j++;
        }
        k = l;
        for (auto it : temp)
        {
            v[k] = it;
            k++;
        }
        return;
    }
    void mergeSort(vector<int> &ans, vector<pair<int, int>> &v, int l, int h)
    {
        if (l < h)
        {
            int mid = l + (h - l) / 2;
            mergeSort(ans, v, l, mid);
            mergeSort(ans, v, mid + 1, h);
            merge(ans, v, l, mid, h);
        }
    }
    vector<int> constructLowerArray(int *arr, int n)
    {
        // code here
        vector<pair<int, int>> v;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
            v.push_back({arr[i], i});
        mergeSort(ans, v, 0, n - 1);
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