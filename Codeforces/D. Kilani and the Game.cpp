#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define vii vector<int>
#define GRAPH vector<vector<char>>
#define pp pair<int, int>

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1}; // 4 directions

map<int, queue<pp>> mp;

int rows, cols, nodes, cnt_empty_cells = 0;
GRAPH graph;
vii speed;

vii cnt_taken_cells;


bool is_valid(int r, int c) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

void bfs(queue<pp>&q , int node){

    for(int level = 0 , sz = q.size() ; !q.empty() && level < speed[node] ; level++ , sz=q.size()){
        while(sz--) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (is_valid(nr, nc) && graph[nr][nc] == '.') {
                    graph[nr][nc] = '0' + node;
                    cnt_empty_cells--;
                    q.push({nr, nc});
                    cnt_taken_cells[node]++;
                }
            }
        }
    }
}


int main() {
    fast;

    cin >> rows >> cols >> nodes;
    graph.resize(rows, vector<char>(cols));
    speed.resize(nodes + 1); // index from 1 to nodes
    cnt_taken_cells.resize(nodes + 1);

    for (int i = 1; i <= nodes; i++) {
        cin >> speed[i];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == '.') {
                cnt_empty_cells++;
            } else if (isdigit(graph[i][j])) {
                int num = graph[i][j] - '0';
                mp[num].push({i, j});
            }
        }
    }

    for (int i = 1; i <= nodes; i++) {
        cnt_taken_cells[i] = mp[i].size();
    }

    while (cnt_empty_cells > 0) {
        for (int i = 1; i <= nodes; i++) {
            bfs(mp[i] , i);
        }
    }

    for (int i = 1; i <= nodes; i++) {
        cout << cnt_taken_cells[i] << ' ';
    }

    return 0;
}
