#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

typedef vector<int> vi;

vector<vi> AdjList;
bool visitado[MAXN];

void BFS(int source) {
	
	queue<int> cola;

	cola.push(source);
	visitado[source] = true;
	while (!cola.empty()) {
		int u = cola.front();
		cola.pop();
		printf("%d ", u);
		for (auto v : AdjList[u]) {
			if (!visitado[v]) {
				visitado[v] = true;
				cola.push(v);
			}
		}
	}
}

int main() {
	
	int V, E, x, y;
	
	scanf("%d %d", &V, &E);
	AdjList.assign(V, vi());
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &x, &y);
		AdjList[x].push_back(y);
		//AdjList[y].push_back(x);
	}
	BFS(2);
	return 0;
}
