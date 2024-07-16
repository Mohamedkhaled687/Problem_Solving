class Solution {
private:
// check if the is a conflict is assigning the color
	bool is_color_conflict = false;

	void dfs(vector<vector<int>> &graph, int node, vector<int> &colors, int assign_color = 1) {
		if (colors[node] == 0)
			colors[node] = assign_color;
		else {
			if (colors[node] != assign_color)
				is_color_conflict = true;
			return;
		}

		for (int neighbour : graph[node])
      /* spliting the nodes and its neighbours into two groups group 1 for nodes and group 2 for its negihbour 
       this done by simulate vector of int of two different numbers which represent the color {1 , 2} */
			dfs(graph, neighbour, colors, 3 - assign_color);
	}
public:
	bool isBipartite(vector<vector<int>> &graph) {
		int nodes = graph.size();
		vector<int> colors(nodes);

		for (int i = 0; i < nodes; ++i) {
			if (colors[i] == 0) {	// New CC
				dfs(graph, i, colors);
				if (is_color_conflict)
					return false;
			}
		}
		return true;
	}
};
