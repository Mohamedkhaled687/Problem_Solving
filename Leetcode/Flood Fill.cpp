class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;

        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        dfs(sr, sc, visited, image, oldColor, color);
        
        return image;
    }

    void dfs(int sr, int sc, vector<vector<bool>>& visited, vector<vector<int>>& image, int oldColor, int newColor) {
        if (!(is_valid(sr, sc, image)) || visited[sr][sc] || image[sr][sc] != oldColor)
            return;

        visited[sr][sc] = true;
        image[sr][sc] = newColor;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            dfs(sr + dr[i], sc + dc[i], visited, image, oldColor, newColor);
        }
    }

    bool is_valid(int r, int c, vector<vector<int>>& image) {
        int row = image.size();
        int col = image[0].size();
        return (r >= 0 && r < row && c >= 0 && c < col);
    }
};
