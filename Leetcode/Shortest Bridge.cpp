// link : https://leetcode.com/problems/shortest-bridge/

// Code : 

class Solution {
    queue<pair<int, int>> q;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool is_valid(vector<vector<int>>& grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int oldcolor = 1, int newcolor = 2) {
        grid[r][c] = newcolor;
        q.push({r, c});

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (!is_valid(grid, nr, nc) || grid[nr][nc] != oldcolor) {
                continue;
            }
            dfs(grid, nr, nc, oldcolor, newcolor);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        // DFS to find the first island and mark it with newcolor (2)
        bool found = false;
        for (int i = 0; i < rows && !found; i++) {
            for (int j = 0; j < cols && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    found = true;
                }
            }
        }

        // BFS to find the shortest path to the second island
        for (int level = 0; !q.empty(); level++) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i], nc = c + dc[i];

                    if (!is_valid(grid, nr, nc) || grid[nr][nc] == 2 || grid[nr][nc] == 3)
                        continue;

                    if (grid[nr][nc] == 1)
                        return level;

                    q.push({nr, nc});
                    grid[nr][nc] = 3;
                }
            }
        }

        return -1; // Should not reach here if input is valid
    }
};
