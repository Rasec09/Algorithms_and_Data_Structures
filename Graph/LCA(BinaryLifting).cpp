#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int logn;
vector<vi> ady, parent;
vi level;

void dfs(int u, int p) {
	parent[u][0] = p;
	for (int i = 1; i <= logn; i++)
		parent[u][i] = parent[parent[u][i - 1]][i - 1];
	for (int v : ady[u]) {
		if (v != p) {
			level[v] = level[u] + 1;
			dfs(v, u);
		}
	}
}

int lca(int u, int v) {
	if (level[u] < level[v])
		swap(u, v);
	for (int i = logn; i >= 0; i--)
		if (level[u] - (1 << i) >= level[v])
			u = parent[u][i];
	if (u == v)
		return u;
	for (int i = logn; i >= 0; i--) {
		if (parent[u][i] != -1 and parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

int dist(int u, int v) {
	return level[u] + level[v] - 2 * level[lca(u, v)];
}

void init(int N) {
	logn = ceil(log2(N));
	level.assign(N, 0);
	parent.assign(N, vi(logn + 1, -1));
	dfs(0, 0);
}

int main() {
	
	int N, a, b;

	scanf("%d", &N);
	ady.assign(N, vi());
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &a, &b);
		ady[a - 1].push_back(b - 1);
		ady[b - 1].push_back(a - 1);
	}
	init(N);
	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + i; j <= N; j += i) {
			ans += dist(i - 1, j - 1) + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
