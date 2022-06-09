#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

vector<int> nextGreater(vector<int> &a) {
	int n = a.size();
	stack<int> s;
	vector<int> r(n, n);
	for (int i = 0; i < n; i++) {
		if (s.empty() or a[s.top()] >= a[i]) {
			s.push(i);
		}
		else {
			while (!s.empty() and a[s.top()] < a[i]) {
				r[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}
	return r;
}

vector<int> prevGreater(vector<int> &a) {
	int n = a.size();
	stack<int> s;
	vector<int> l(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		if (s.empty() or a[s.top()] >= a[i]) {
			s.push(i);
		}
		else {
			while (!s.empty() and a[s.top()] < a[i]) {
				l[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}
	return l;
}

int main() {
  return 0;
}
