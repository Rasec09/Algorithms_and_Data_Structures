#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_low, dfs_num, Stack, visited;
int dfsContador, numSCC;

vector<vi> scc; // Resultado

void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsContador++;
	Stack.push_back(u);
	visited[u] = 1;
	for (int i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (dfs_num[v] == -1)
			tarjanSCC(v);
		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]) {
		++numSCC;
		vi componente;
		while (1) {
			int v = Stack.back(); Stack.pop_back();
			visited[v] = 0;
			componente.push_back(v);
			if (u == v) break;
		}
		scc.push_back(componente);
	}
}

// Devuelve el grafo formado por las componentes fuertemente conexas
vector<vi> condensedGraph(vector<vi> &adj, vector<vi> &scc, int n) {
	vector<vi> adj_scc;
	set<pair<int,int>> edges;
	map<int,int> vertexSCC;

	for (int i = 0; i < scc.size(); i++) {
		for (int v : scc[i]) {
			vertexSCC[v] = i;
		}
	}

	for (int i = 0; i < adj.size(); i++) {
		for (int v : adj[i]) {
			if (vertexSCC[i] != vertexSCC[v])
				edges.insert(make_pair(vertexSCC[i], vertexSCC[v]));
		}
	}
	adj_scc.assign(scc.size(), vi());
	for (auto e : edges) {
		adj_scc[e.first].push_back(e.second);
	}
	return adj_scc;
}

int main() {
	
	int N, M, V, W, P;

	while (scanf("%d %d", &N, &M), (N || M)) {
		AdjList.assign(N, vi());
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &V, &W, &P);
			AdjList[--V].push_back(--W);
			if (P == 2)
				AdjList[W].push_back(V);
		}

		dfsContador = numSCC = 0;
		dfs_num.assign(N, -1);
		dfs_low.assign(N, 0);
		visited.assign(N, 0);
		
		for (int i = 0; i < N; i++)
			if (dfs_num[i] == -1)
				tarjanSCC(i);

		printf(numSCC == 1 ? "1\n" : "0\n");
		scc.clear();
	}
	return 0;
}
