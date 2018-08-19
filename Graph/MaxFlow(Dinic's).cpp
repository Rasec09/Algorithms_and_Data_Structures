#include <bits/stdc++.h>
using namespace std;

typedef long long int flow_type;
typedef vector<int> vi;

struct Edge {
	int src, dst, rev;
	flow_type capacity, flow;
	Edge(int u, int v, int r, flow_type cap, flow_type f):
	src(u), dst(v), rev(r), capacity(cap), flow(f) {}
};

vector<vector<Edge> > adj;
vi dist, iter;

//Arista bidireccional
void addEdge(int u, int v, flow_type cap) {
	adj[u].push_back(Edge(u, v, (int)adj[v].size(), cap, 0));
	adj[v].push_back(Edge(v, u, (int)adj[u].size() - 1, cap, 0));
}

bool dinic_bfs(int nodes, int source, int sink) {
	dist.assign(nodes, -1);
	dist[source] = 0;
	queue<int> q;
	q.push(source);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int j = 0; j < (int)adj[u].size(); j++) {
			Edge &e = adj[u][j];
			if (dist[e.dst] < 0 && e.flow < e.capacity) {
				dist[e.dst] = dist[u] + 1;
				q.push(e.dst);
			}
		}
	}
	return dist[sink] >= 0;
}

flow_type dinic_dfs(int u, int sink, flow_type f) {
	if (u == sink)
		return f;
	for (int &i = iter[u]; i < (int)adj[u].size(); i++) {
		Edge &e = adj[u][i];
		if (dist[e.dst] == dist[u] + 1 && e.flow < e.capacity) {
			flow_type flow = dinic_dfs(e.dst, sink, min(f, e.capacity - e.flow));
			if (flow > 0) {
				e.flow += flow;
				adj[e.dst][e.rev].flow -= flow;
				return flow;
			}
		}
	}
	return 0;
}

//Algoritmo de Dinic nodos numerados 0 a n - 1
//Complejidad: O(V^2 * E)
flow_type dinic(int nodes, int source, int sink) {
	flow_type maxflow = 0;
	while (dinic_bfs(nodes, source, sink)) {
		iter.assign(nodes, 0);
		while (flow_type flow = dinic_dfs(source, sink, numeric_limits<flow_type>::max())) {
			maxflow += flow;
		}
	}
	return maxflow;
}

int main() {
	
	int N, M, u, v, c;

	scanf("%d %d", &N, &M);
	adj.assign(N, vector<Edge>());
	while (M--) {
		scanf("%d %d %d", &u, &v, &c);
		if (u == v) continue;
		addEdge(u - 1, v - 1, c);
	}
	printf("%lld\n", dinic(N, 0, N - 1));
	return 0;
}
