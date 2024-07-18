#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false) , cin.tie(nullptr) , cout.tie(nullptr);

void add_edge_un_directed(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool dfs_bipartite(GRAPH &graph, int node, vii &color, int assign_color = 1) {
    color[node] = assign_color;

    for (auto &neighbour : graph[node]) {
        if (color[neighbour] == 0) {
            if (!dfs_bipartite(graph, neighbour, color, 3 - assign_color)) {
                return false;
            }
        } else if (color[neighbour] == color[node]) {
            return false;
        }
    }
    return true;
}

int main() {
    fast;

    int nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes + 1);

    for (int i = 0; i < edges; i++) {
        int from, to;
        cin >> from >> to;
        add_edge_un_directed(graph, from, to);
    }

    vector<int> color(nodes + 1, 0);
    int bench_count = 0;

    for (int i = 1; i <= nodes; i++) {
        if (color[i] == 0) {
            if (!dfs_bipartite(graph, i, color)) {
                bench_count++;
            }
        }
    }

    if((nodes - bench_count) & 1)
        bench_count++;

    cout << bench_count << endl;

}
