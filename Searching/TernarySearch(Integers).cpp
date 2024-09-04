// test: https://codeforces.com/contest/2009/problem/E 
#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef int64_t ll;
 
ll sum(ll l, ll r) { // sum of numbers in range [l,r]
	ll res = (r - l + 1) * (l + r);
	res >>= 1;
	return res;
}
 
ll f(ll x, ll l, ll r) {
	ll res = sum(l, x);
	res -= sum(x + 1, r);
	if (res < 0) res *= -1;
	return res;
}
 
int32_t main() {
	optimizar_io
	int tc, n, k;
 
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		ll l = k, r = k + n - 1;
		while (r - l > 2) {
			ll m1 = l + (r - l) / 3;
        	ll m2 = r - (r - l) / 3;
       	 	ll f1 = f(m1, k, k + n - 1);
        	ll f2 = f(m2, k, k + n - 1);
        	// cout << f1 << " " << f2 << "\n";
			if (f1 > f2) // Busca el valor donde f es minimo
            	l = m1;
        	else
            	r = m2;
		}
		ll ans = numeric_limits<ll>::max();
		for (int i = l; i <= r; i++) {
			ans = min(ans, f(i, k, k + n - 1));
		}
		cout << ans << "\n";
	}
	return 0;
}
