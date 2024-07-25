
// Important problem , link : https://leetcode.com/problems/sliding-puzzle/


// Code (hench : write in Clion with getting input by user not on Leet code)


#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


int rows, cols;
GRAPH graph;

vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 0}};

bool is_valid(int r, int c) {
    return r >= 0 && r < graph.size() && c >= 0 && c < graph[0].size();
}

struct VectorHash {
    std::size_t operator()(const std::vector<std::vector<int>>& vv) const {
        std::size_t seed = vv.size();
        for (const auto& v : vv) {
            for (int i : v) {
                seed ^= std::hash<int>()(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
        }
        return seed;
    }
};



bool areMatricesEqual(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    return mat1 == mat2;
}

int BFS(unordered_map<vector<vector<int>>, int, VectorHash>& visited, int r, int c) {
    queue<pair<vector<vector<int>>, pair<int, int>>> q;
    visited[graph] = 1;
    q.push({graph, {r, c}});

    for (int level = 0; !q.empty(); ++level) {
        int sz = q.size();

        while (sz--) {
            auto [currGraph, coords] = q.front();
            auto [r, c] = coords;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (is_valid(nr, nc)) {
                    vector<vector<int>> temp = currGraph;
                    swap(temp[r][c], temp[nr][nc]);
                    if (visited[temp] != 1 && areMatricesEqual(temp, arr)) {
                        return level + 1;
                    }
                    if (visited[temp] != 1) {
                        visited[temp] = 1;
                        q.push({temp, {nr, nc}});
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    fast;

    cin >> rows >> cols;
    graph.resize(rows, vii(cols));

    int start_r = -1, start_c = -1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) {
                start_r = i;
                start_c = j;
            }
        }
    }

    if (start_r == -1 || start_c == -1) {
        cout << "Invalid start position\n";
        return 1;
    }

    unordered_map<vector<vector<int>>, int, VectorHash> visited;

    cout << BFS(visited, start_r, start_c) << endl;

    return 0;
}
