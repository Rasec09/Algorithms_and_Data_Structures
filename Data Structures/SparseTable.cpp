#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

struct SparseTable {
	int n;
	vector<int> a;
	vector<vector<int>> rmq;

	SparseTable(vector<int>& _a) : a(_a), n(_a.size()) {
		rmq.assign(n, vector<int>(18));
		for (int i = 0; i < n; ++i) rmq[i][0] = i;
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 0; i + (1 << j) - 1 < n; i++) {
				int x = rmq[i][j - 1];
				int y = rmq[i + (1 << (j - 1))][j - 1];
				rmq[i][j] = (a[x] > a[y]) ? x : y;
			}
		}
	}

	int query(int i, int j) {
		int k = 31 - __builtin_clz(j - i + 1);
		int x = rmq[i][k];
		int y = rmq[j - (1 << k) + 1][k];
		return a[x] > a[y] ? x : y;
	}
};

int main() {
	
	return 0;
}
