class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int cnt = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    // Flag to check if the current island is closed
                    isClosed = true;
                    dfs(i, j, grid, visited);
                    if (isClosed) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    bool isClosed;

    bool is_valid(int r, int c, vector<vector<int>>& grid) {
        return (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size());
    }

    bool is_bound(int r, int c, vector<vector<int>>& grid) {
        return r == 0 || r == grid.size() - 1 || c == 0 || c == grid[0].size() - 1;
    }

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (!is_valid(r, c, grid) || grid[r][c] == 1 || visited[r][c]) {
            return;
        }

        visited[r][c] = true;

        // If this cell is on the boundary, mark the island as not closed
        if (is_bound(r, c, grid)) {
            isClosed = false;
        }

        // Traverse all 4 directions
        for (int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i], grid, visited);
        }
    }
};
