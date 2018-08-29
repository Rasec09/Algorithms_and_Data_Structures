#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> adj;
vi match;
vector<bool> visited;

bool dfs(int u) {
	if (visited[u]) return false;
	visited[u] = true;
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}

int kuhn(int n1, int n2) {
	visited.assign(n1, false);
	match.assign(n2, -1);
	int matches = 0;
	for (int i = 0; i < n1; i++) {
		visited.assign(n1, false);
		if (dfs(i))
			matches++;
	}
	return matches;
}

int main() {
	
	int N, M, E, x, y;

    scanf("%d %d %d", &N, &M, &E);
    adj.assign(N, vi());
    while (E--) {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
    }
    printf("%d\n", kuhn(N, M));
    /*for (int i = 0; i < match.size(); i++) {
    	if (match[i] != -1) {
      		printf("%d %d\n", match[i], i);
    	}
	}*/
	return 0;
}
