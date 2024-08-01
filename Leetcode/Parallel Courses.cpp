#include <bits/stdc++.h>

using namespace std;


int nodes;
GRAPH graph;

int top_sort() {
    vii in_degree(nodes + 1, 0);

    for (int i = 1; i <= nodes; i++) {
        for (auto &j : graph[i])
            in_degree[j]++;
    }

    queue<int> q;

    for (int i = 1; i <= nodes; i++)
        if (in_degree[i] == 0)
            q.push(i);

    vii ordering;

    int level = 0;
    for (int sz = q.size(); !q.empty(); level++, sz = q.size()) {
        while (sz--) {
            int cur = q.front();
            q.pop();
            ordering.push_back(cur);

            for (auto &i : graph[cur]) {
                if (--in_degree[i] == 0)
                    q.push(i);
            }
        }
    }

    if (ordering.size() != nodes) 
        return -1;
    else
        return level;
}

int main() {
  
    int edges;
    cin >> nodes >> edges;
    graph.resize(nodes + 1);

    while (edges--) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    cout << top_sort() << endl;
}
