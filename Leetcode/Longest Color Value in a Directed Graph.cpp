// Link : https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/

// Code




class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int nodes = colors.size();

      // Intializing the adj.list and inde
        vector<vector<int>> graph(nodes);
        vector<int> indegree(nodes);

        for(int i = 0 ; i < edges.size() ; i++){
            int from = edges[i][0]  , to = edges[i][1];
            graph[from].push_back(to);

          // Increasing indegree of the nodes that edge going to it
            indegree[to]++;
        }

      // Readu queue to push all nodes with non indegree
        queue<int> ready;

        for(int i = 0 ; i < nodes; i ++)
            if(!indegree[i])
                ready.push(i);


      // vector to maxmize the color of the each node 
        vector<vector<int>> mx_colors(nodes , vector<int> (26));

        int mx = 0;
        int popped_nodes = 0;

        while(!ready.empty()){
            int cur = ready.front() , color = colors[cur] - 'a';
            ready.pop();
            mx_colors[cur][color] += 1;
            ++popped_nodes;

            mx = max(mx , mx_colors[cur][color]);

            for(int &neighbour : graph[cur]){

                for(int x = 0 ; x < 26 ; x++){
                    mx_colors[neighbour][x] = max(mx_colors[neighbour][x] , mx_colors[cur][x]);
                }

                if(--indegree[neighbour] == 0)
                    ready.push(neighbour);
            }

        }

      // check if there is a cycle
        if(nodes != popped_nodes)
            return -1;

        return mx;
    }
};
