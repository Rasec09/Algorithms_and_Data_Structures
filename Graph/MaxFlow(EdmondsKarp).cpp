#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
	int src, dst, rev, capacity, flow;
	Edge(int u, int v, int r, int cap, int f) : 
	src(u), dst(v), rev(r), capacity(cap), flow(f) {}
};

vector<vector<Edge> > adj;

void addEdge(int u, int v, int cap) {
	adj[u].push_back(Edge(u, v, (int)adj[v].size(), cap, 0));
	adj[v].push_back(Edge(v, u, (int)adj[u].size() - 1, 0, 0));
}

// Algoritmo de Edmonds-Karp nodos numerados 0 a n - 1
// Complejidad: O(V * E^2)
int EdmondsKarp(int nodes, int source, int sink) {
	int maxflow = 0;
	for (;;) {
		vector<Edge*> pred(nodes, (Edge*)0);
		queue<int> q;
		q.push(source);
		while (!q.empty() && !pred[sink]) {
			int u = q.front();
			q.pop();
			for (int j = 0; j < (int)adj[u].size(); j++) {
				Edge &e = adj[u][j];
				if (!pred[e.dst] && e.capacity > e.flow) {
					pred[e.dst] = &e;
					q.push(e.dst);
				}
			}
		}
		if (!pred[sink]) break;
		int flow = INF;
		for (int u = sink; u != source; u = pred[u]->src)
			flow = min(flow, pred[u]->capacity - pred[u]->flow);
		for (int u = sink; u != source; u = pred[u]->src) {
			pred[u]->flow += flow;
			adj[pred[u]->dst][pred[u]->rev].flow -= flow;
		}
		maxflow += flow;
	}
	return maxflow;
}

int main() {
	
	int n, m, s, t;

	scanf("%d %d %d %d", &n, &m, &s, &t);
	adj.assign(n, vector<Edge>());
	while (m--) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		addEdge(u, v, c);
	}
	int maxflow = EdmondsKarp(n, s, t), numEdges = 0;
	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (adj[i][j].flow > 0)
				numEdges++;
		}
	}
	printf("%d %d %d\n", n, maxflow, numEdges);
	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			if (adj[i][j].flow > 0) {
				printf("%d %d %d\n", adj[i][j].src, adj[i][j].dst, adj[i][j].flow);
			}
		}
	}
	return 0;
}
