// link : https://leetcode.com/problems/pacific-atlantic-water-flow/submissions/1332288798/

// code

class Solution {
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool is_valid(vector<vector<int>>& heights, int r, int c) {
        return r >= 0 && r < heights.size() && c >= 0 && c < heights[0].size();
    }

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, vector<pair<int, int>>& starting) {
        queue<pair<int, int>> q;

        for (const auto& start : starting) {
            int r = start.first, c = start.second;
            visited[r][c] = true;
            q.push({r, c});
        }

        while (!q.empty()) {
            int cur_r = q.front().first, cur_c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = cur_r + dr[i], nc = cur_c + dc[i];
                if (is_valid(heights, nr, nc) && !visited[nr][nc] && heights[nr][nc] >= heights[cur_r][cur_c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();

        vector<vector<bool>> pacific_reachable(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic_reachable(rows, vector<bool>(cols, false));

        vector<pair<int, int>> pacific_starting;
        vector<pair<int, int>> atlantic_starting;

        for (int c = 0; c < cols; ++c) {
            pacific_starting.push_back({0, c});
            atlantic_starting.push_back({rows - 1, c});
        }

        for (int r = 0; r < rows; ++r) {
            pacific_starting.push_back({r, 0});
            atlantic_starting.push_back({r, cols - 1});
        }

        bfs(heights, pacific_reachable, pacific_starting);
        bfs(heights, atlantic_reachable, atlantic_starting);

        vector<vector<int>> result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (pacific_reachable[i][j] && atlantic_reachable[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }
};
