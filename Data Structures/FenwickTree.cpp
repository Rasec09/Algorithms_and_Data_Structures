#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {

	int *ft, size;

	FenwickTree(int n) : size(n) {
		ft = new int[n + 1];
		for (int i = 0; i <= n; i++)
			ft[i] = 0;
	}

	void update(int idx, int val) {
		while (idx <= size) {
			ft[idx] += val;
			idx += (idx & -idx);
		}
	}

	int query(int idx) {
		int sum = 0;
		while (idx > 0) {
			sum += ft[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}

	int range(int i, int j) {
		return query(j) - query(i - 1);
	}
};

int main() {
	
	return 0;
}
