class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int row = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(cols, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    bool hasCycle = false;
                    dfs(grid, i, j, -1, -1, grid[i][j], visited, hasCycle);
                    if (hasCycle) return true;
                }
            }
        }
        return false;
    }

private:
    bool is_valid(int r, int c, vector<vector<char>>& grid) {
        return (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size());
    }

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(vector<vector<char>>& grid, int r, int c, int pr, int pc, char def, vector<vector<bool>>& visited, bool &hasCycle) {
        if (!is_valid(r, c, grid) || grid[r][c] != def) return;

        if (visited[r][c]) {
            hasCycle = true;
            return;
        }

        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr == pr && nc == pc) continue; // Skip the parent cell
            dfs(grid, nr, nc, r, c, def, visited, hasCycle);
            if (hasCycle) return; // Early exit if a cycle is found
        }
    }
};
