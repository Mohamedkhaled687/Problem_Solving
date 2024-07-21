// link https://codeforces.com/contest/1627/problem/C

#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define vii vector<int>
#define vib vector<bool>
#define vil vector<int>
#define vis vector<string>
#define pp pair<int, int>
#define GRAPH vector<vector<int>>
int mx = INT_MIN;
int mn = INT_MAX;
const double EPS = 1e-9;
const double pi = 3.14159265358979323846;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
map<int, int> val_to_idx;
map<int, int> idx_to_val;

int nodes, edges;
GRAPH graph;
vib visited;

map<pp, int> mp;
bool two = true;

void add_edge_un_directed(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(int node, int parent_node , int assign_num = 2) {
    if (visited[node])
        return;

    visited[node] = true;
    if (parent_node != -1) {
        mp[{node, parent_node}] = assign_num;
        mp[{parent_node, node}] = assign_num;
    }

    for (auto &neighbour : graph[node]) {
        if (!visited[neighbour])
            dfs(neighbour, node, 5 - assign_num);
    }
}

int main() {
    fast;

    int t;
    cin >> t;
    while (t--) {
        cin >> nodes;
        edges = nodes - 1;

        // Clear data structures for each test case
        graph.assign(nodes + 1, vector<int>());
        visited.assign(nodes + 1, false);
        mp.clear();

        vector<pp> edges_v;
        for (int i = 0; i < edges; i++) {
            int from, to;
            cin >> from >> to;
            add_edge_un_directed(graph, from, to);
            edges_v.push_back({from, to});
        }

        int starting = -1;
        bool check = false;
        for (int node = 1; node <= nodes; node++) {
            if (graph[node].size() == 1)
                starting = node;
            if (graph[node].size() > 2) {
                check = true;
            }
        }
        if (check) {
            cout << -1 << endl;
            continue;
        }

        dfs(starting, -1);
        

        for (auto &pair : edges_v) {
            cout << mp[{pair.first, pair.second}] << ' ';
        }

        cout << endl;
    }

    return 0;
}
