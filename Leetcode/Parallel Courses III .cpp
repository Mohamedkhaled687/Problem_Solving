
// link : https://leetcode.com/problems/parallel-courses-iii/?source=submission-ac

// Code

class Solution {
public:
    int minimumTime(int nodes, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(nodes + 1);
        vector<int> result(nodes + 1, -1); // Initialize result with -1

        for(int i = 0 ; i < relations.size() ; i++){
            int from = relations[i][0] , to = relations[i][1];
            graph[from].push_back(to);
        }

        for(int i = 1 ; i <= nodes; i++){
            dfs(i, result, graph, time);
        }

        return *max_element(result.begin(), result.end());
    }

    int dfs(int node, vector<int> &result, vector<vector<int>> &graph, vector<int> &time){
        if(result[node] != -1)
            return result[node];

        int res = time[node - 1];
        for(auto &neighbour : graph[node]){
            res = max(res, time[node - 1] + dfs(neighbour, result, graph, time));
        }

        result[node] = res;
        return res; // Ensure dfs returns a value
    }
};
