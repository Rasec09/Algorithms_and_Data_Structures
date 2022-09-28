// tested: https://codeforces.com/contest/1730/problem/B
#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int32_t main() {
	optimizar_io
	int tc, n;
	array<int,100000> x, t;
 
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> x[i];
		for (int i = 0; i < n; i++) cin >> t[i];
 
		auto f = [&](double x0) -> double {
			double res = 0;
			for (int i = 0; i < n; i++) {
				res = max(res, t[i] + abs(x[i] - x0));
			}
			return res;
		};
 
		double l = 0, r = 1e9, eps = 1e-9;
		while (fabs(l - r) > eps) {
			double m1 = l + (r - l) / 3;
        	double m2 = r - (r - l) / 3;
       	 	double f1 = f(m1);
        	double f2 = f(m2);
			if (f1 > f2) // Busca el valor donde f es minimo
            	l = m1;
        	else
            	r = m2;
		}
		cout << fixed;
		cout << setprecision(9) << l << "\n";
	}
	return 0;
}
