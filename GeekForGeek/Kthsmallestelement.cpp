#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int partition(int arr[], int l, int r)
    {
        int pivotElement = arr[r];
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (pivotElement >= arr[j])
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[r], arr[i + 1]);
        return i + 1;
    }

    int kthSmallest(int arr[], int l, int r, int k)
    {
        if (l <= r)
        {
            int pivot = partition(arr, l, r);
            if (pivot == k - 1)
                return arr[pivot];
            else if (pivot < k - 1)
                return kthSmallest(arr, pivot + 1, r, k);
            else
                return kthSmallest(arr, l, pivot - 1, k);
        }
        return -1;
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