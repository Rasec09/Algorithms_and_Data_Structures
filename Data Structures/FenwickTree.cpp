#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct FenwickTree {
	
	int size;
	vector<ll> ft;

	FenwickTree(int n) : size(n) {
		ft.assign(n + 1, 0);
	}

	void update(int idx, ll val) {
		while (idx <= size) {
			ft[idx] += val;
			idx += (idx & -idx);
		}
	}

	ll query(int idx) {
		ll sum = 0;
		while (idx > 0) {
			sum += ft[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}

	ll range(int i, int j) {
		return query(j) - query(i - 1);
	}
};

int main() {
	
	return 0;
}
