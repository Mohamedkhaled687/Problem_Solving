// link of problem : https://codeforces.com/problemset/problem/1063/B


#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define pp pair<int, int>
#define GRAPH vector<vector<char>>

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int rows, cols, start_r, start_c, lef, rih, cnt = 0;
GRAPH graph;

struct State {
    int r, c, left, right;

    bool operator<(const State &other) const {
        return left + right < other.left + other.right;
    }
};

bool is_valid(int r, int c) {
    return r > 0 && r <= rows && c > 0 && c <= cols && graph[r][c] == '.';
}

void bfs() {
    priority_queue<State> q;
    q.push({start_r, start_c, 0, 0});
    graph[start_r][start_c] = '*';

    while (!q.empty()) {
        State cur = q.top();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];

            if (!is_valid(nr, nc)) continue;

            if (i == 1 && cur.right < rih) { // Move right
                q.push({nr, nc, cur.left, cur.right + 1});
                graph[nr][nc] = '*';
            }
            else if (i == 3 && cur.left < lef) { // Move left
                q.push({nr, nc, cur.left + 1, cur.right});
                graph[nr][nc] = '*';
            }
            else if (i == 0 || i == 2) { // Move up or down
                q.push({nr, nc, cur.left, cur.right});
                graph[nr][nc] = '*';
            }
        }
    }
}

int main() {
    fast;

    cin >> rows >> cols >> start_r >> start_c >> lef >> rih;

    graph.resize(rows + 1, vector<char>(cols + 1));

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            cin >> graph[i][j];
        }
    }

    bfs();
    cout << cnt;

    return 0;
}
