#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1e9;

vector<vii> Ady;
vi dist;

bool BellmanFord(int s, int V) {
	dist[s] = 0;
	for (int i = 0; i < V - 1; i++) {
		for (int u = 0; u < V; u++) {
			for (auto v : Ady[u])
				if (dist[u] < INF)
					dist[v.first] = min(dist[v.first], dist[u] + v.second);
		}
	}
	bool cicloNegativo = false;
	for (int u = 0; u < V; u++) {
		for (auto v : Ady[u])
			if (dist[v.first] > dist[u] + v.second)
				cicloNegativo = true;			
	}
	return cicloNegativo;
}

int main() {
	
	int TC, V, E, a, b, w;

	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &V, &E);
		Ady.assign(V, vii());
		dist.assign(V, INF);
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &a, &b, &w);
			Ady[a].push_back(ii(b, w));
		}
		printf( BellmanFord(0, V) ? "possible\n" : "not possible\n" );
	}
	return 0;
}
