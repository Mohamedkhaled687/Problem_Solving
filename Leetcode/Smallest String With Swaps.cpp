class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int nodes = s.size();
        vector<vector<int>> graph(nodes);

        for(auto &pair : pairs) {
            add_edge(graph, pair[0], pair[1]);
        }
        
        vector<bool> visited(nodes, false);

        for(int i = 0; i < nodes; i++) {
            vector<int> arr;
            if(!visited[i]) {
                dfs(graph, i, visited, arr);

                string temp;
                for(int index : arr) {
                    temp += s[index];
                }

                sort(temp.begin(), temp.end());
                sort(arr.begin(), arr.end());
                
                for(int j = 0; j < arr.size(); j++) {
                    s[arr[j]] = temp[j];
                }
            }
        }
        
        return s;
    }
private:
    void add_edge(vector<vector<int>> &graph, int from, int to) {
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<int>& arr) {
        if(visited[node])
            return;

        visited[node] = true;
        arr.push_back(node);

        for(auto &neighbour : graph[node]) {
            dfs(graph, neighbour, visited, arr);
        }
    }
};
