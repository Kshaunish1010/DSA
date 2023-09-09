#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    // Function to return the sorted array.
    vector<int> nearlySorted(int arr[], int n, int k)
    {
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (pq.size() == k + 1)
            {
                ans.push_back(pq.top());
                pq.pop();
            }
            pq.push(arr[i]);
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
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