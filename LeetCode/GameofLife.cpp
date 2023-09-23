#include <bits/stdc++.h>
using namespace std;
#define turbo                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0}; // Changes in row index
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1}; // Changes in column index
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cnt = 0;
                for (int k = 0; k < 8; k++)
                {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m && board[nr][nc] == 1)
                    {
                        cnt++;
                    }
                }
                if (board[i][j] == 1 && cnt > 1 && cnt < 4)
                    v[i][j] = 1;
                else if (cnt == 3)
                    v[i][j] = 1;
            }
        }
        board = v;
    }
};

//inplace 
class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        int n = board.size(), m = board[0].size();
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0}; // Changes in row index for 8 directions
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1}; // Changes in column index for 8 directions
        
        // Loop through each cell in the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0; // Count of live neighbors
                
                // Check each of the 8 possible directions
                for (int k = 0; k < 8; k++) {
                    int nr = i + dr[k]; // New row index
                    int nc = j + dc[k]; // New column index
                    
                    // Check if the new position is valid and contains a live cell (1) or a previously dead cell (2)
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m && (board[nr][nc] == 1 || board[nr][nc] == 2)) {
                        cnt++;
                    }
                }
                
                // Apply the rules of the Game of Life:
                // 1. If a live cell has fewer than 2 live neighbors or more than 3 live neighbors, it dies (marked as 2).
                // 2. If a dead cell has exactly 3 live neighbors, it becomes alive (marked as 3).
                if (board[i][j] == 1 && (cnt < 2 || cnt > 3))
                    board[i][j] = 2;
                else if (board[i][j] == 0 && cnt == 3)
                    board[i][j] = 3;
            }
        }
        
        // Update cell states based on the marked values:
        // 2 becomes 0 (dead) and 3 becomes 1 (alive)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                if (board[i][j] == 3)
                    board[i][j] = 1;
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