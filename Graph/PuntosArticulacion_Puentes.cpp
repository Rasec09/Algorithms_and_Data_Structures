#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> ListAdy;
vi dfs_low, dfs_num, puntos_articulacion, dfs_parent;
vii puentes;
int dfsContador, dfsRoot, rootHijo;

void PuntosArticulacion_Puentes(int u) {
	dfs_low[u] = dfs_num[u] = dfsContador++;
	for (int i = 0; i < ListAdy[u].size(); i++) {
		ii v = ListAdy[u][i];
		if (dfs_num[v.first] == -1) { //No visitado
			dfs_parent[v.first] = u;
			if (u == dfsRoot) rootHijo++;  //Si rootHijo > 1 root es PA
			PuntosArticulacion_Puentes(v.first);
			if (dfs_low[v.first] >= dfs_num[u]) //Punto de articulacion
				puntos_articulacion[u] = true;
			if (dfs_low[v.first] > dfs_num[u]) //Puente
				puentes.push_back(ii(min(u, v.first), max(u, v.first)));
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
		}
		else if (v.first != dfs_parent[u]) 
			dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
	}
}

int main() {
	
	int V, E, x, y;
    
    scanf("%d %d", &V, &E); //Numero de vertices y numero de aristas
    ListAdy.assign(V, vii());
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &x, &y); //Origen y destino
        ListAdy[ x ].push_back( ii(y, 0) );
        ListAdy[ y ].push_back( ii(x, 0) );
    }

	dfsContador = 0;
	dfs_low.assign(V, 0);
	dfs_num.assign(V, -1);
	dfs_parent.assign(V, -1);
	puntos_articulacion.assign(V, 0);

	for (int i = 0; i < V; i++) {
		if (dfs_num[i] == -1) {
			dfsRoot = i; rootHijo = 0;
			PuntosArticulacion_Puentes(i);
			puntos_articulacion[dfsRoot] = (rootHijo > 1);
		}
	}
	sort(puentes.begin(), puentes.end());

	int pa = 0;
	for (int i = 0; i < V; i++) 
		if (puntos_articulacion[i]) pa++;

	printf("%d\n", pa);
	for (int i = 0; i < V; i++) {
		if (puntos_articulacion[i]) printf("%d ", i);
	}
	printf("\n");

	printf("%u\n", puentes.size());
	for (int i = 0; i < puentes.size(); i++) {
		printf("%d %d\n", puentes[i].first, puentes[i].second);
	}
	return 0;
}
