#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

typedef int64_t ll;
const ll MOD = 1e9+7;
ll fact[1000010];

ll mod(ll a, ll b = MOD) {
	return ((a % b) + b) % b;
}

void getFactorials() {
	fact[0] = 1;
	for (ll i = 1; i <= 1000000; i++) {
		fact[i] = mod(i * fact[i - 1]);
	}
}

ll powMod(ll a, ll n, ll m) {
	ll result = 1;
	while (n) {
		if (n & 1)
			result = mod(result * a, m);
		a = mod(a * a, m);
		n >>= 1;
	}
	return result;
}

ll invMod(ll a, ll m = MOD) {
	return powMod(a, m - 2, m);
}

// n! / r! * (n - r)! 
ll nCr(int n, int r) {
	ll ans = fact[n];
	ll denominador = mod(fact[r] * fact[n - r]);
	ans = mod(ans * invMod(denominador, MOD));
	return ans;
}

int32_t main() {
	optimizar_io

	return 0;
}
