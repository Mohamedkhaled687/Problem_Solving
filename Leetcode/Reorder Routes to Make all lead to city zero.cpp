#include <vector>
using namespace std;

class Solution {
private:
    struct edge {
        int to;
        bool direction;
    };

    void add_edge(vector<vector<edge>>& graph, int from, int to) {
        graph[from].push_back({to, true});
        graph[to].push_back({from, false});
    }

    void dfs(vector<vector<edge>>& graph, int node, vector<bool>& visited, int& cnt) {
        if (visited[node])
            return;
        visited[node] = true;

        for (auto& neighbour : graph[node]) {
            if (!visited[neighbour.to]) {
                cnt += neighbour.direction;
                dfs(graph, neighbour.to, visited, cnt);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<edge>> graph(n);  // Initialize the graph with size n
        for (int i = 0; i < connections.size(); i++) {
            add_edge(graph, connections[i][0], connections[i][1]);
        }

        vector<bool> visited(n, false);  // Initialize the visited vector with size n

        int cnt = 0;
        dfs(graph, 0, visited, cnt);

        return cnt;
    }
};
