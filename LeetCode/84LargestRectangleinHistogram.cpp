#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// code 1 (brute force)
class Solution
{
public:
    vector<int> l;
    vector<int> r;
    int n;
    void nsl(vector<int> &heights)
    {
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && s.top().first >= heights[i])
            {
                s.pop();
            }
            if (s.empty())
                l.push_back(-1);
            else
                l.push_back(s.top().second);
            s.push({heights[i], i});
        }
    }
    void nsr(vector<int> &heights)
    {
        stack<pair<int, int>> s;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top().first >= heights[i])
            {
                s.pop();
            }
            if (s.empty())
                r.push_back(n);
            else
                r.push_back(s.top().second);
            s.push({heights[i], i});
        }
        reverse(r.begin(), r.end());
    }
    int largestRectangleArea(vector<int> &heights)
    {
        n = heights.size();
        int area = INT_MIN;
        nsl(heights);
        nsr(heights);
        for (int i = 0; i < n; i++)
        {
            area = max(area, heights[i] * (r[i] - l[i] - 1));
        }
        return area;
    }
};
// code 2(optimised)
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