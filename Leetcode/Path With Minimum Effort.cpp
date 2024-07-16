class Solution {
private:
	int dr[4] { -1, 0, 1, 0 };
	int dc[4] { 0, 1, 0, -1 };

	bool isvalid(int r, int c, vector<vector<int>> &heights) {
		if (r < 0 || r >= (int) heights.size())
			return false;
		if (c < 0 || c >= (int) heights[0].size())
			return false;
		return true;
	}

	// We can use external flag. But let's code to return true
	bool dfs(int r, int c, vector<vector<int>> &heights, vector<vector<bool>> &visited, int limit) {
		if (r == (int) heights.size() - 1 && c == (int) heights[0].size() - 1)
			return true;	// If reached the destination: base case for true

		visited[r][c] = 1;

		for (int d = 0; d < 4; ++d) {
			int nr = r + dr[d], nc = c + dc[d];
			if (!isvalid(nr, nc, heights) || visited[nr][nc] || abs(heights[r][c] - heights[nr][nc]) > limit)
				continue;

			if (dfs(nr, nc, heights, visited, limit))	// can we reach from this cell?
				return true;
		}
		return false;
	}

	bool possible(vector<vector<int>> &heights, int mid) {
		vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size()));
		return dfs(0, 0, heights, visited, mid);
	}

public:
	int minimumEffortPath(vector<vector<int>> &heights) {	// O(MN logMax) time
		int start = 0, end = 1000000;	// The max height from the statement
		int result = end;

		while (start <= end) {
			int mid = (start + end) / 2;
			if (possible(heights, mid))
				end = mid - 1, result = mid;
			else
				start = mid + 1;
		}
		return result;
	}
};
