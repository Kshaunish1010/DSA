#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define MAX 1000

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> s;
        int area = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i]))
            {
                int h = heights[s.top()];
                s.pop();
                int w;
                if (s.empty())
                    w = i;
                else
                {
                    w = i - s.top() - 1;
                }
                area = max(area, w * h);
            }
            s.push(i);
        }
        return area;
    }
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // Your code here
        vector<int> heights(m, 0);
        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j])
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
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