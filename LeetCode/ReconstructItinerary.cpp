#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    vector<string> ans;

    void dfs(unordered_map<string, vector<string>> &adj, string node)
    {
        while (!adj[node].empty())
        {
            string next_dest = adj[node].back();
            adj[node].pop_back();
            dfs(adj, next_dest);
        }
        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, vector<string>> adj;

        // Build the adjacency list
        for (auto &ticket : tickets)
        {
            adj[ticket[0]].push_back(ticket[1]);
        }

        // Sort the destinations in lexical order
        for (auto &pair : adj)
        {
            sort(pair.second.begin(), pair.second.end(), greater<string>());
        }

        dfs(adj, "JFK");
        reverse(ans.begin(), ans.end()); // Reverse to get the correct order

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