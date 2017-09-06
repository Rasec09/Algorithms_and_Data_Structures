#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
int AdjMatrix[200][200];

void FloydWarshall(int V) {

	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);
}

int main() {
	
	int TC, V, E, a, b, w, q;

	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &V, &E);
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++)
				AdjMatrix[i][j] = INF;
			AdjMatrix[i][i] = 0;
		}
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &a, &b, &w);
			AdjMatrix[--a][--b] = min(w, AdjMatrix[a][b]);
			AdjMatrix[b][a] = AdjMatrix[a][b];
		}
		FloydWarshall(V);
		scanf("%d", &q);
		while (q--) {
			scanf("%d %d", &a, &b);
			AdjMatrix[--a][--b] == INF ? printf("-1\n") : printf("%d\n", AdjMatrix[a][b]);
		}
		if(TC) printf("\n");
	}
	return 0;
}
