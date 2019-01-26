#include <bits/stdc++.h>
using namespace std;
#define MAXN 200010
#define LOGN 20

typedef vector<int> vi;

vector<vi> ady;
vector<int> first, euler, level;

void dfs(int from, int u, int depth) {
	first[u] = level.size();
	euler.push_back(u);
	level.push_back(depth);
	for (int i = 0; i < (int)ady[u].size(); i++) {
		int v = ady[u][i];
		if (from != v) {
			dfs(u, v, depth + 1);
			euler.push_back(u);
			level.push_back(depth);
		}
	}
}

int sparse[MAXN][LOGN];
int logs[MAXN];

void initLCA(int root, int n) {
	first.resize(n);
	dfs(root, root, 0);
	for (int i = 2; i <= euler.size(); i++)
		logs[i] = logs[i >> 1] + 1;

	for (int i = 0; i < euler.size(); i++)
		sparse[i][0] = i;

	for (int j = 1; (1 << j) <= euler.size(); j++) {
		for (int i = 0; i + (1 << j) - 1 < euler.size(); i++) {
			int x = sparse[i][j - 1];
			int y = sparse[i + (1 << (j - 1))][j - 1];
			sparse[i][j] = (level[x] < level[y]) ? x : y;
		}
	}
}

int rmq(int i, int j) {
	int k = logs[j - i + 1];
	int x = sparse[i][k];
	int y = sparse[j - (1 << k) + 1][k];
	return level[x] < level[y] ? x : y;
}

int lca(int u, int v) {
	int i = first[u], j = first[v];
	if (i > j) swap(i, j);
	return euler[rmq(i, j)];
}

int main() {
	
	int n, q, u, v;

	scanf("%d", &n);
	ady.assign(n, vi());
	for (int i = 0; i < n; i++) {
		scanf("%d", &u);
		while (u--) {
			scanf("%d", &v);
			ady[i].push_back(v);
			ady[v].push_back(i);
		}
	}
	initLCA(0, n);
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}
