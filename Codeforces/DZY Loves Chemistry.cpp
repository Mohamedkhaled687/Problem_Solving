#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll long long
#define vii vector<int>
#define vib vector<bool>
#define vil vector<int>
#define vis vector<string>
#define pp pair<int, int>
#define GRAPH vector<vector<int>>
const double EPS = 1e-9;
const double pi = 3.14159265358979323846;

void add_edge_un_directed(GRAPH &graph, ll from, ll to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(GRAPH &graph, ll node, vib &visited, ll &component_size) {
    visited[node] = true;
    component_size++;
    for (auto &neighbour : graph[node]) {
        if (!visited[neighbour]) {
            dfs(graph, neighbour, visited, component_size);
        }
    }
}

int main() {
    fast;

    ll nodes, edges;
    cin >> nodes >> edges;

    GRAPH graph(nodes + 1);

    for (ll i = 0; i < edges; i++) {
        ll from, to;
        cin >> from >> to;
        add_edge_un_directed(graph, from, to);
    }

    vector<bool> visited(nodes + 1, false);
    ll result = 1;

    for (ll i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            ll component_size = 0;
            dfs(graph, i, visited, component_size);
            result *= pow(2, component_size - 1);
        }
    }

    cout << result;

    return 0;
}
