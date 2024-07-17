// link of problem https://codeforces.com/contest/862/problem/B

#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
#define vii vector<int>
#define GRAPH vector<vector<int>>

void add_edge_un_directed(GRAPH &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs_bipartite(GRAPH &graph, int node, vii &color, bool &check, int assign_color = 1) {
    if (color[node] == 0)
        color[node] = assign_color;
    else {
        if (color[node] != assign_color) {
            check = false;
            return;
        }
    }

    for (auto &neighbour : graph[node]) {
        if (color[neighbour] == 0)
            dfs_bipartite(graph, neighbour, color, check, 3 - assign_color);
        else if (color[neighbour] == color[node]) {
            check = false;
            return;
        }
    }
}

int main() {
    fast;

    int nodes;
    cin >> nodes;

    GRAPH graph(nodes + 1);

    for (int i = 0; i < nodes - 1; i++) {
        int from, to;
        cin >> from >> to;
        add_edge_un_directed(graph, from, to);
    }

    vector<int> color(nodes + 1, 0);
    bool check = true;

    // Only need to check bipartiteness starting from node 1
    dfs_bipartite(graph, 1, color, check);

    if (!check) {
        cout << "Graph is not bipartite." << endl;
        return 0;
    }

    int count1 = count(color.begin(), color.end(), 1);
    int count2 = count(color.begin(), color.end(), 2);

    // Calculate the maximum number of edges that can be added
    int max_edges = count1 * count2 - (nodes - 1);

    cout << max_edges << endl;

    return 0;
}
