#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
	int numSets;
	vector<int> padre, rango, numVertices;

	UnionFind(int N) : numSets(N) {
		padre.assign(N + 1, 0);
		rango.assign(N + 1, 0);
		numVertices.assign(N + 1, 0);
		for (int i = 0; i <= N; ++i) {
			padre[i] = i;
			rango[i] = 0;
			numVertices[i] = 1;
		}
	}

	int findSet(int x) {
        return (x == padre[x]) ? x : (padre[x] = findSet(padre[x]));
    }

    bool isSameSet(int x, int y) {
       	return findSet(x) == findSet(y);
    }

    void unionSet(int x, int y) {
        int xRoot = findSet(x);
        int yRoot = findSet(y);
		if (!isSameSet(xRoot, yRoot)) {
			if (rango[xRoot] > rango[yRoot]) {
				padre[yRoot] = xRoot;
				numVertices[xRoot] += numVertices[yRoot];
			}
			else {
				padre[xRoot] = yRoot;
				numVertices[yRoot] += numVertices[xRoot];
				if (rango[xRoot] == rango[yRoot])
					rango[yRoot]++;
			}
            numSets--;
        }
    }

    int sizeOfSet(int x) {
    	return numVertices[findSet(x)];
    }
};

int main() {

	return 0;
}
