#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;
typedef vector<long long int> vi;

// Calcula el gcd(a, b)
ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

// Multiplicacion binaria a*b mod m
ll mulMod(ll a, ll b, ll m) {
	/*ll result = 0;
	while (b) {
		if (b & 1)
			result = (result + a) % m;
		a = (a + a) % m;
		b >>= 1;
	}
	return result;*/
	return (a * b) % m;
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

ll absolute(ll a) {
	if (a < 0) a *= -1;
	return a;
}

ll PollardRho(ll n, ll seed) {
	ll x, y;
	x = y = rand() % (n - 1) + 1;
	int head = 1, tail = 2;
	while (true) {
		x = mulMod(x, x, n);
		x = (x + seed) % n;
		if (x == y) return n;
		ll d = gcd(absolute(y - x), n);
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

//Obtiene los divisores de un numero a partir de sus factores primos donde ocu es el exponente del pf
void divisors(vi &d, vi &pf, vi &ocu, int idx, ll S) {
	if (idx == pf.size()) {
		d.push_back(S);
		return;
	}
	else {
		for (int i = 0; i <= ocu[idx]; i++) {
			divisors(d, pf, ocu, idx + 1, S);
			S *= pf[idx];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int TC;
	long long int n;

	cin >> TC;
	while (TC--) {
		cin >> n;
		vi factors;
		factorize(n, factors);
		sort(factors.begin(), factors.end());
		cout << factors[0];
		for (int i = 1; i < factors.size(); i++)
			cout << " " << factors[i];
		cout << "\n";
	}
	return 0;
}
