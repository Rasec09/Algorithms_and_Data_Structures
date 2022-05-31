/*
* Segment Tree Dinamico
* Range Query - Point Update
* Tested: https://cses.fi/problemset/task/1648/
*/
#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

struct SegTree {
	ll val;
	int low, hig;
	SegTree *l, *r;

	SegTree(int lo, int hi) : val(0), low(lo), hig(hi), l(nullptr), r(nullptr) {}

	void build(vector<int> &a) {
		if (low == hig) {
			val = a[low];
			return;
		}
		int mid = (low + hig) / 2;
		l = new SegTree(low, mid), l -> build(a);
		r = new SegTree(mid + 1, hig); r -> build(a);
		val = l -> val + r -> val;
	}

	void extend() {
		if (!l) {
			int mid = (low + hig) / 2;
			l = new SegTree(low, mid);
			r = new SegTree(mid + 1, hig);
		}
	}

	void update(int idx, ll x) {
		if (idx < low or hig < idx) return;
		if (idx == low and idx == hig) {
			val = x;
			return;
		}
		extend();
		l -> update(idx, x);
		r -> update(idx, x);
		val = l -> val + r -> val;
	}

	ll query(int i, int j) {
		if (j < low or hig < i) return 0;
		if (i <= low and hig <= j) return val;
		extend();
		return l -> query(i, j) + r -> query(i, j);
	}
};

int32_t main() {
	optimizar_io
	int n, q, type, idx, val, l, r;

	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	SegTree st(0, n - 1);
	st.build(a);
	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> idx >> val;
			st.update(idx - 1, val);
		}
		else {
			cin >> l >> r;
			cout << st.query(l - 1, r - 1) << "\n";
		}
	}
	return 0;
}
