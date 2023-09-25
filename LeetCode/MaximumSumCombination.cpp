#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution {
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B)
    {
        // Sort vectors A and B in non-increasing order
        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());
        
        // Create a priority queue to store pairs (sum, index) where sum is A[i] + B[j] and index represents the current index of B
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < N; i++)
        {
            pq.push({A[i] + B[0], 0});
        }
        
        vector<int> ans;
        // Perform K iterations or until the priority queue is empty
        while (!pq.empty() && K--)
        {
            auto it = pq.top();
            int sum = it.first;
            int x = it.second;
            ans.push_back(sum);
            
            // Calculate the sum for the next combination by subtracting B[x] and adding B[x+1]
            int nsum = sum - B[x] + B[x + 1];
            
            pq.pop();
            pq.push({nsum, x + 1}); // Push the new sum into the priority queue
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