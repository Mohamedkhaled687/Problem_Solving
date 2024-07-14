class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid2.size();
        int col = grid2[0].size();
        int cnt = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid2[i][j] == 1) {
                    bool check = true;
                    dfs(grid1, grid2, i, j, check);
                    if (check) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }

private:
    // Directoin arrays 
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool is_valid(int r, int c, vector<vector<int>>& grid) {
        return (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size());
    }

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, bool& check) {
        if (!is_valid(r, c, grid2) || grid2[r][c] == 0) {
            return;
        }

        if (grid1[r][c] == 0) {
            check = false;
        }

        grid2[r][c] = 0; // Mark the cell as visited

        for (int i = 0; i < 4; ++i) {
            dfs(grid1, grid2, r + dr[i], c + dc[i], check);
        }
    }
};
