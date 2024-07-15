class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> degree;

        // adding the edgesa and count degrees of the nodes
        for (const auto& pair : adjacentPairs) {
            add_edge(graph, pair[0], pair[1]);
            degree[pair[0]]++;
            degree[pair[1]]++;
        }

        // checking the degree to be start node must have only one neighnour
        int start = 0;
        for (const auto& [node, deg] : degree) {
            if (deg == 1) {
                start = node;
                break;
            }
        }

        unordered_set<int> visited;
        vector<int> arr;

        dfs(graph, start, visited, arr);

        return arr;
    }

private:
    void add_edge(unordered_map<int, vector<int>>& graph, int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    void dfs(unordered_map<int, vector<int>>& graph, int node, unordered_set<int>& visited, vector<int>& arr) {
        visited.insert(node);
        arr.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                dfs(graph, neighbor, visited, arr);
            }
        }
    }
};
