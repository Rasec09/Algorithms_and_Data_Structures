#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
	
	int size;
	vector<int> ft;

	FenwickTree(int n) : size(n) {
		ft.assign(n + 1, 0);
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
