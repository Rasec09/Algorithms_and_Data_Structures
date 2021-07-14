#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int INF = 1e9;
vector<vi> AdjList;
vi dfs_num, topologicalSort, dist, numPaths;

void OrdenTopologico(int u) {
	dfs_num[u] = 1;
	for (int i = 0; i < AdjList[u].size(); ++i) {
		int v = AdjList[u][i];
		if (dfs_num[v] == -1)
			OrdenTopologico(v);
	}
	topologicalSort.push_back(u);
}

// Orden topologico lexicograficamente menor
vi topologicalSort(vector<vi> &AdjList, int V) {
	vi orden;
	vi in_degree(V, 0);
 
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < AdjList[i].size(); j++) {
			in_degree[AdjList[i][j]]++;
		}
	}
 
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);
 
	while (!q.empty()) {
		int v = q.top();
		q.pop();
		orden.push_back(v);
		for (int i = 0; i < AdjList[v].size(); i++) {
			in_degree[AdjList[v][i]]--;
			if (in_degree[AdjList[v][i]] == 0)
				q.push(AdjList[v][i]);
		}
	}
	return orden;
}

//Caminos mas largo en un DAG desde la fuente s requiere el topoSort
int longestPath(int V, int s) {
	dist.assign(V, -INF); //Cambiar -INF por 0 si no hay fuente
	dist[s] = 0;
	for (int i = 0; i < topologicalSort.size(); i++) {
		int u = topologicalSort[i];
		if (dist[u] != -INF) { //Quitar este if si no hay fuente
			for (int j = 0; j < AdjList[u].size(); j++) {
				int v = AdjList[u][j];
				if (dist[v] < dist[u] + 1) // Cambiar el < a > para el camino mas corto
					dist[v] = dist[u] + 1;
			}
		}
	}
	int longest = -INF;
	for (int i = 0; i < dist.size(); i++) {
		longest = max(longest, dist[i]);
	}
	return longest;
}

//Cuenta el numero de caminos en un DAG requiere el topoSort
int countPaths(int V) {
	numPaths.assign(V, 0);
	numPaths[0] = 1;
	for (int i = 0; i < topologicalSort.size(); i++) {
		int u = topologicalSort[i];
		for (int j = 0; j < AdjList[u].size(); j++) {
			int v = AdjList[u][j];
			numPaths[v] += numPaths[u];
		}
	}
	int paths = 0;
	for (int i = 0; i < AdjList.size(); i++)
		if (AdjList[i].empty())
			paths += numPaths[i];
	return paths;
}

int main() {

	int V, E, u, v;

	scanf("%d %d", &V, &E);
	AdjList.assign(V, vi());
	while (E--) {
		scanf("%d %d", &u, &v);
		AdjList[u].push_back(v);
	}

	dfs_num.assign(V, -1);
	topologicalSort.clear();
	for (int i = 0; i < V; ++i)
		if (dfs_num[i] == -1)
			OrdenTopologico(i);
	reverse(topologicalSort.begin(), topologicalSort.end());
	
	for (int i = 0; i < topologicalSort.size(); ++i) {
		printf("%d ", topologicalSort[i]);
	}
	printf("\n");
	return 0;
}
