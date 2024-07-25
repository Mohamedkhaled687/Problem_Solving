// link : https://leetcode.com/problems/shortest-path-with-alternating-colors/submissions/1333127143/

// COde : 

class Solution {
public:

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
      // intialize result vector with all non visited values
        vector<int> result(n, -1);
        vector<vector<pair<int, int>>> graph(n);

        // Construct the graph with red and blue edges
        for (int edge = 0; edge < redEdges.size(); edge++) {
            int from = redEdges[edge][0], to = redEdges[edge][1];
            graph[from].emplace_back(to, 0); // 0 for red edge
        }
        for (int edge = 0; edge < blueEdges.size(); edge++) {
            int from = blueEdges[edge][0], to = blueEdges[edge][1];
            graph[from].emplace_back(to, 1); // 1 for blue edge
        }

        queue<pair<int, int>> q; // pair of (node, edge color)
        q.emplace(0, -1); // -1 indicates starting point, no color
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        visited[0][0] = visited[0][1] = true;

        result[0] = 0;
        for (int level = 0; !q.empty(); level++) {
            for (int sz = q.size(); sz > 0; sz--) {
                auto [cur, curColor] = q.front();
                q.pop();

                for (const auto& [neighbour, color] : graph[cur]) {
                    if (color != curColor && !visited[neighbour][color]) {
                        visited[neighbour][color] = true;
                        q.emplace(neighbour, color);
                        if (result[neighbour] == -1) {
                            result[neighbour] = level + 1;
                        }
                    }
                }
            }
        }
        return result;
    }
};
