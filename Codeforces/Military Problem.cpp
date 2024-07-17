#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
#define ll long long
#define vii vector<int>
#define vib vector<bool>
#define vil vector<ll>
#define vis vector<string>
#define pp pair<int, int>
#define GRAPH vector<vector<int>>
const double EPS = 1e-9;
const double pi = 3.14159265358979323846;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
map<int, int> val_to_idx;
map<int, int> idx_to_val;
struct edge {
    int to;
    int cost;

    bool operator<(const edge &e) const {
        if (to == e.to)
            return cost < e.cost;
        return to < e.to;
    }
};
void add_edge(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
}


void dfs_cycle(const GRAPH &graph, int node, vector<bool> &visited, bool &hasCycle, int parent = -1) {
    visited[node] = true;
    for (auto &neighbour : graph[node]) {
        if (neighbour == parent)
            continue;

        if (visited[neighbour]) {
            hasCycle = true;
            return;
        }

        if (!visited[neighbour]) {
            dfs_cycle(graph, neighbour, visited, hasCycle, node);
            if (hasCycle) return;
        }
    }
}


void dfs(GRAPH &graph, int node, vector<int> &dfs_order, vector<int> &subtree_size, vector<int> &entry, int &current_time) {
    entry[node] = current_time;
    dfs_order.push_back(node);
    current_time++;

    for (auto &neighbour : graph[node]) {
        dfs(graph, neighbour, dfs_order, subtree_size, entry, current_time);
    }

    subtree_size[node] = current_time - entry[node];
}


int main() {
    fast;

    int nodes, queries;
    cin >> nodes >> queries;

    GRAPH graph(nodes + 1);

    vector<int> supervisors(nodes + 1);
    for (int i = 2; i <= nodes; i++) {
        cin >> supervisors[i];
        add_edge(graph, supervisors[i], i);
    }

    vector<int> dfs_order;
    vector<int> subtree_size(nodes + 1, 0);
    vector<int> entry(nodes + 1, 0);

    int current_time = 0;
    dfs(graph, 1, dfs_order, subtree_size, entry, current_time);

    while (queries--) {
        int super, k;
        cin >> super >> k;

        int start_idx = entry[super];
        int required_idx = start_idx + k - 1;

        if (required_idx >= dfs_order.size() || required_idx >= start_idx + subtree_size[super]) {
            cout << -1 << endl;
        } else {
            cout << dfs_order[required_idx] << endl;
        }
    }

    return 0;
}
