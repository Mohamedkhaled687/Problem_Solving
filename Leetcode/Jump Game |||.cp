class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int nodes = arr.size();
        vector<vector<int>> graph(nodes);
        vector<bool> visited(nodes, false);

        // Building the graph
        for (int i = 0; i < nodes; ++i) {
            int next = i + arr[i], back = i - arr[i];
            if (back >= 0 && back != i)
                graph[i].push_back(back);
            if (next < nodes && next != i)
                graph[i].push_back(next);
        }

        queue<int> q;
        q.push(start);
        visited[start] = true;

        if (arr[start] == 0)
            return true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto &neighbour : graph[cur]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    if (arr[neighbour] == 0)
                        return true;
                }
            }
        }

        return false;
    }
};
