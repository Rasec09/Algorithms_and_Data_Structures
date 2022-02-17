#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
#define isOn(S, j) (S & (1 << j))
#define turnOn(S, j) (S | (1 << j))

int n, G[18][18], memo[16][(1 << 15) + 5];

int tsp(int pos, int mask) {
	if (mask == ((1 << n) - 1)) return G[pos][0];
	if (memo[pos][mask] != -1) return memo[pos][mask];
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		if (i != pos and !isOn(mask, i))
			ans = min(ans, tsp(i, turnOn(mask, i)) + G[pos][i]);
	}
	return memo[pos][mask] = ans;
}

int main() {
	optimizar_io
	int m, u, v, w;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				G[i][j] = 0;
			else
				G[i][j] = 1e9;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w; 
		G[u][v] = w;
	}
	memset(memo, -1, sizeof(memo));
	int ans = tsp(0, 1);
	if (ans != 1e9)
		cout << ans << "\n";
	else
		cout << "-1\n";
	return 0;
}
