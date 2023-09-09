#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
// User function Template for C++

class Solution
{
public:
    int maxValueK(vector<int> &A)
    {
        // Code Here

        int n = A.size();
        // priority_queue<int>pq;
        // for(auto it: A){
        //     pq.push(it);
        // }
        // int cnt=0;
        // while(!pq.empty()){
        //     if(pq.top()<cnt+1){
        //         return cnt;
        //     }
        //     cnt++;
        //     pq.pop();
        // }
        // sort(A.begin(),A.end(),greater<int>());
        // for(int i=0;i<n;i++){
        //     if(A[i]<i+1) return i;
        // }
        vector<int> count(n + 1, 0);
        for (int x : A)
        {
            if (x <= n)
            {
                count[x]++;
            }
            else
            {
                count[n]++;
            }
        }
        int sum = 0;
        for (int i = n; i >= 1; --i)
        {
            sum += count[i];
            if (sum >= i)
            {
                return i;
            }
        }
        return 0;
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