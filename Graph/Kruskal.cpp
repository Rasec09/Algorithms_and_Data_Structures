#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> arista;
vector <arista> aristas;

struct UnionFind {
	
	int numSets;
	int *padres;
	int *numVertices;

	UnionFind(int N) : numSets(N) {
		padres = new int[N + 1];
		numVertices = new int[N + 1];
		for (int i = 0; i <= N; ++i) {
			padres[i] = i;
			numVertices[i] = 1;
		}
	}

	int findSet(int x) {
        return (x == padres[x]) ? x : (padres[x] = findSet(padres[x]));
    }

    bool isSameSet(int x, int y) {
       	return findSet(x) == findSet(y);
    }

    void unionSet(int x, int y) {
        int xRoot = findSet(x);
        int yRoot = findSet(y);
		if (!isSameSet(xRoot, yRoot)) {
            numVertices[yRoot] += numVertices[xRoot];
            padres[xRoot] = yRoot;
            numSets--;
        }
    }

    int sizeOfSet(int x) {
    	return numVertices[findSet(x)];
    }
};

vector<arista> kruskal(int N) {
    
    vector<arista> mst;
    UnionFind componentes(N);

    sort(aristas.begin(), aristas.end());
    for (int i = 0; i < aristas.size(); i++) {
        int u = aristas[i].second.first;
        int v = aristas[i].second.second;
        if (!componentes.isSameSet(u, v)) {
            mst.push_back(aristas[i]);
            componentes.unionSet(u, v);
        }
    }
    return mst;
}

int main() {

    int V, E, a, b, w;

    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &a, &b, &w);
        aristas.push_back(arista(w, ii(a, b)));
    }
    vector<arista> mst = kruskal(V);
    int total = 0;
    for (int i = 0; i < mst.size(); i++)
        total += mst[i].first;
    printf("%d\n", total);
    return 0;
}
