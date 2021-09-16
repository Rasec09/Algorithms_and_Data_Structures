// Tested: https://www.hackerrank.com/contests/101hack22/challenges/sum-of-all-distances/problem
#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> ady;
vector<int64_t> subTreeSz, dist;

void dfs(int from, int u) {
	subTreeSz[u] = 1;
	for (auto &[v, w] : ady[u]) {
		if (v != from) {
			dfs(u, v);
			subTreeSz[u] += subTreeSz[v];
			dist[u] += dist[v] + (w * subTreeSz[v]);
		}
	}
}

void reRoot(int n, int from, int u) {		
	for (auto &[v, w] : ady[u]) {
		if (v != from) {
			int64_t rem = dist[u] - (dist[v] + w * subTreeSz[v]);
			dist[v] += rem + w * (n - subTreeSz[v]);
			reRoot(n, u, v);
		}
	}
}

int main() {
	optimizar_io
	int tc, n, u, v, w;

	cin >> tc;
	while (tc--) {
		cin >> n;
		ady.assign(n, vii());
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v >> w;
			u--; v--;
			ady[u].emplace_back(v, w);
			ady[v].emplace_back(u, w);
		}
		subTreeSz.assign(n, 0);
		dist.assign(n, 0);
		dfs(0, 0);
		reRoot(n, 0, 0);
		for (auto x : dist) cout << x << "\n";
	}
	return 0;
}
