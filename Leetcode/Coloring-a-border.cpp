class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int oldColor = grid[row][col];
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        dfs(grid, visited, row, col, oldColor);

        // Apply new color to the border cells
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (visited[i][j] && isBorder(grid, visited, i, j, oldColor)) {
                    grid[i][j] = color;
                }
            }
        }

        return grid;
    }

private:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool is_valid(int r, int c, vector<vector<int>>& grid) {
        return (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size());
    }

    bool isBorder(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int oldColor) {
        if (r == 0 || r == grid.size() - 1 || c == 0 || c == grid[0].size() - 1) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (is_valid(nr, nc, grid) && !visited[nr][nc]) {
                if (grid[nr][nc] != oldColor) {
                    return true;
                }
            }
        }

        return false;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int oldColor) {
        if (!is_valid(r, c, grid) || grid[r][c] != oldColor || visited[r][c]) {
            return;
        }

        visited[r][c] = true;

        for (int i = 0; i < 4; ++i) {
            dfs(grid, visited, r + dr[i], c + dc[i], oldColor);
        }
    }
};
