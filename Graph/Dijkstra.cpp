#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 1000000000;

vector<vii> Ady;
vi dist, parent;

void dijkstra(int s) {

	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));

	while (!pq.empty()) {
		ii front = pq.top();
		pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		for (auto v : Ady[u]) {
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				parent[v.first] = u;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
}

void printPath(int des) {
	if (parent[des] != -1)
		printPath(parent[des]);
	printf(" %d", des + 1);
}

int main() {
	
	int V, E, a, b, w;

	scanf("%d %d", &V, &E);
	Ady.assign(V, vii());
	dist.assign(V, INF);
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &w);
		Ady[--a].push_back(ii(--b, w));
	}
	parent.assign(V, -1);
	dijkstra(0);
	for (int i = 1; i < V; i++)
		printf("%d ", dist[i]);
	return 0;
}
