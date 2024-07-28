void add_undirected_edge(GRAPH &graph, int from, int to) {
	graph[from].push_back(to);
	graph[to].push_back(from);
}

pair<int, int> bfs(GRAPH &adjList, int start) {
	const int OO = 10000000;	// A big value expressing infinity
	vector<int> len(adjList.size(), OO);
	queue<int> q;
	q.push(start);
	len[start] = 0;

	int cur = 0, level = 0, sz = 1;
	for (; !q.empty(); ++level, sz = q.size()) {
		while (sz--) {
			cur = q.front();
			q.pop();
			for (int neighbour : adjList[cur])
				if (len[neighbour] == OO) {	// never visited
					q.push(neighbour);
					len[neighbour] = level + 1;
				}
		}
	}
	return {cur, len[cur]};	// farthest node and its level
}

int treeDiam(GRAPH &graph) {
	pair<int, int> p1 = bfs(graph, 0);	// Get farthest node from 0
	p1 = bfs(graph, p1.first);			// Get farthest node from this farthest node
	return p1.second;
}

int main() {
	// This 2 lines can speed the reading with cin
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int nodes;
	cin >> nodes;

	GRAPH graph(nodes + 1);

	for (int i = 0; i < nodes - 1; i++) {
		int x, y;
		cin >> x >> y;
		add_undirected_edge(graph, x - 1, y - 1);
	}
	cout << treeDiam(graph) << "\n";

	return 0;
}
