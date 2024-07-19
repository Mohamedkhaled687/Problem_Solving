// link of the problem https://codeforces.com/contest/1365/problem/D
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define GRAPH vector<vector<char>>
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int rows, cols;

bool is_valid(GRAPH &graph, int r, int c) {
    return (r >= 0 && r < graph.size() && c >= 0 && c < graph[0].size());
}

void dfs(GRAPH &graph, int r, int c, vector<vector<bool>> &visited) {
    if (!is_valid(graph, r, c) || visited[r][c] || graph[r][c] == '#')
        return;

    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        dfs(graph, nr, nc, visited);
    }
}

int main() {
    fast;

    int t;
    cin >> t;

    while (t--) {
        cin >> rows >> cols;

        GRAPH graph(rows, vector<char>(cols));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));


        int cnt_G = 0 , cnt_B = 0;

        for (auto &i : graph) {
            for (auto &j : i) {
                cin >> j;
                cnt_G += j == 'G';
                cnt_B += j == 'B';
            }
        }

        if(cnt_G == 0 && cnt_B > 0){
            cout << "YES" << endl;
            continue;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (graph[i][j] == 'B') {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dr[k], nj = j + dc[k];
                        if (is_valid(graph, ni, nj) && graph[ni][nj] == '.') {
                            graph[ni][nj] = '#';
                        }
                    }
                }
            }
        }

        if (graph[rows-1][cols-1] == '#') {
            cout << "NO" << endl;
            continue;
        }

        // Perform DFS from the exit
        dfs(graph, rows-1, cols-1, visited);

        bool valid = true;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (graph[i][j] == 'G' && !visited[i][j]) {
                    valid = false;
                }
                if (graph[i][j] == 'B' && visited[i][j]) {
                    valid = false;
                }
            }
        }

        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
