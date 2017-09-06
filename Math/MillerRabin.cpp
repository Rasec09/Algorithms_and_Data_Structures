#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll mulMod(ll a, ll b, ll m) {
	ll result = 0;
	while (b) {
		if (b & 1)
			result = (result + a) % m;
		a = (a + a) % m;
		b >>= 1;
	}
	return result;
}

ll powMod(ll a, ll n, ll m) {
	ll result = 1;
	while (n) {
		if (n & 1)
			result = mulMod(result, a, m);
		a = mulMod(a, a, m);
		n >>= 1;
	}
	return result;
}

bool isPrime(ll n) {
    
    if (n < 2) return false;
    if (n != 2 && n % 2 == 0) return false;
    
    ll d = n - 1;
    while (d % 2 == 0)
        d >>= 1;

    for (int i = 0; i < 15; i++) {
        ll a = rand() % (n - 1) + 1, tmp = d;
        ll x = powMod(a, d, n);
        while (tmp != n - 1 && x != 1 && x != n - 1) {
            x = mulMod(x, x, n);
            tmp <<= 1;
        }
        if (x != n - 1 && tmp % 2 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
	
	int TC;
	ll n;

	scanf("%d", &TC);
	while (TC--) {
		scanf("%lld", &n);
		if (isPrime(n))
			printf("prime\n");
		else
			printf("composite\n");
	}
	return 0;
}
