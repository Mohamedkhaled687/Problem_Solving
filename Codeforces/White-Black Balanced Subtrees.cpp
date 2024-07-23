#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using vii = vector<int>;
using GRAPH = vector<vector<int>>;

int cnt = 0;
GRAPH graph;
string color;

void dfs(int node, int &cnt_b, int &cnt_w) {
    int local_b = 0, local_w = 0;
    if (color[node] == 'B') local_b++;
    else local_w++;

    for (auto &neighbour : graph[node]) {
        int sub_b = 0, sub_w = 0;
        dfs(neighbour, sub_b, sub_w);
        local_b += sub_b;
        local_w += sub_w;
    }

    if (local_b == local_w) cnt++;
    cnt_b = local_b;
    cnt_w = local_w;
}

void solve() {
    cnt = 0;
    int nodes;
    cin >> nodes;
    graph.assign(nodes + 1, vector<int>());

    for (int i = 2; i <= nodes; i++) {
        int parent;
        cin >> parent;
        graph[parent].push_back(i);
    }

    cin >> color;
    color = '*' + color;  // Ensure 1-based indexing

    int cnt_b = 0, cnt_w = 0;
    dfs(1, cnt_b, cnt_w);
    cout << cnt << endl;
}

int main() {
    fast;
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
