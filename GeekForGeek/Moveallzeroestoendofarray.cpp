#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    void pushZerosToEnd(int arr[], int n) {
    int cnt = 0; // Initialize a counter to keep track of non-zero elements

    // Loop through the array
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            // If the current element is non-zero, swap it with the element at the 'cnt' position
            swap(arr[i], arr[cnt]);
            cnt++; // Increment the counter to move forward
        }
    }
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