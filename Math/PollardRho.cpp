#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

// Calcula el gcd(a, b)
ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

// Multiplicacion binaria a*b mod m
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

// Exponenciacion Binaria a^n mod m
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

// Prueba de primalidad de Miller-Rabin
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

ll PollardRho(ll n, ll seed) {
	ll x, y;
	x = y = rand() % (n - 1) + 1;
	int head = 1, tail = 2;
	while (true) {
		x = mulMod(x, x, n);
		x = (x + seed) % n;
		if (x == y) return n;
		ll d = gcd(abs(y - x), n);
		if (d != 1 && d != n) return d;
		if (++head == tail) y = x, tail <<= 1;
	}
}

void factorize(ll n, vi &factors) {
	//printf("%lld\n", n);
	if (n == 1) return;
	if (isPrime(n)) factors.push_back(n);
	else {
		ll d = n;
		while (d >= n) d = PollardRho(n, rand() % (n - 1) + 1); 
		factorize(d, factors);
		factorize(n / d, factors);
	}
}

int main() {
	
	int TC;
	ll n;
	vi factors;
	map<ll, int> r;

	scanf("%d", &TC);
	while (TC--) {
		scanf("%lld", &n);
		factorize(n, factors);
		for (auto f : factors)
			r[f]++;
		printf("%lld =", n);
		for (auto it = r.begin(); it != r.end(); it++) {
        	if (it != r.begin())
            	printf(" *");
        	printf(" %lld", it->first);
        	if (it->second > 1)
        	printf("^%d", it->second);
        }
        printf("\n");
        factors.clear();
        r.clear();
	}
	return 0;
}
