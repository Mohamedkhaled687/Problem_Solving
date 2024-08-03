// Link of Problem : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/1343020503/


// Code

#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define vii vector<int>
#define vib vector<bool>
#define vil vector<int>
#define vis vector<string>
#define pp pair<int, int>
#define GRAPH vector<vector<int>>
const double EPS = 1e-9;
const double pi = 3.14159265358979323846;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int rows, cols;
int mx = INT_MIN;
GRAPH graph;
vector<vector<int>> memo;

bool is_valid(int r, int c) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

int dfs(int r, int c) {

  // return the value of the Path of element if it computed before
    if (memo[r][c] != -1) 
      return memo[r][c];

  // Computing the Max of element[r][c]
    int maxLength = 1;
    for (int i = 0; i < 4; i++) {
        int nr = dr[i] + r, nc = dc[i] + c;

        if (is_valid(nr, nc) && graph[nr][nc] > graph[r][c]) {
            maxLength = max(maxLength, 1 + dfs(nr, nc));
        }
    }

    memo[r][c] = maxLength;
    return maxLength;
}

int main() {
    fast
    cin >> rows >> cols;

    graph.resize(rows, vector<int>(cols));
    memo.resize(rows, vector<int>(cols, -1));

    for (auto &row : graph) {
        for (auto &val : row) {
            cin >> val;
        }
    }

    
    int maxPathLength = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maxPathLength = max(maxPathLength, dfs(i, j));
        }
    }

    cout << maxPathLength;
    return 0;
}
