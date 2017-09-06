#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

typedef vector<int> vi;

vector<vi> AdyList;
bool visited[MAXN];

void DFS(int u) {
	visited[u] = true;
	for (auto v : AdyList[u]) {
		if (!visited[v]) 
			DFS(v);
	}
}

int main() {
	
	int V, E, x, y;

	scanf("%d %d", &V, &E);
	AdyList.assign(V + 1, vi());
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &x, &y);
		AdyList[x].push_back(y);
		AdyList[y].push_back(x);
	}
	scanf("%d", &x);
	
	DFS(x);

	int sol = 0;
	for (int i = 1; i <= V; i++)
		if (!visited[i])
			sol++;
	printf("%d\n", sol);
	
	return 0;
}
