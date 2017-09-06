#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

// Calcula a % b (valor positivo)
ll mod(ll a, ll b) {
	return ((a % b) + b) % b;
}

// Calcula gcd(a, b)
ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

// Calcula lcm(a, b)
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
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
			result = mod(result * a, m);
		a = mod(a * a, m);
		n >>= 1;
	}
	return result;
}

// Algoritmo extendido de euclides resuelve: ax + by = gcd(a, b)
ll extendedEuclid(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	else {
		ll x1, y1;
		ll d = extendedEuclid(b, a % b, x1, y1);
		x = y1;
		y = x1 - (a / b) * y1;
		return d;
	}
}

// Resuelve ax = 1 (mod n), devuelve -1 si no existe inverso
ll modInv(ll a, ll n) {
	ll x, y;
	ll d = extendedEuclid(a, n, x, y);
	if (d != 1) return -1;
	return mod(x, n);
}

// Resuelve ax + by = c, devulve -1 si no existe solucion
ll linear_diophantine(ll a, ll b, ll c, ll &x, ll &y) {
	ll d = gcd(a, b);
	if (c % d != 0) {
		x = y = -1;
	} else {
		x = c / d * modInv(a / d, b / d);
		y = (c - a * x) / b; 
	}
	return d;
}

// Encuentra todas las soluciones de a*x = b (mod n)
vi modular_linear_equation(ll a, ll b, ll n) {
	ll x, y, d;
	vi soluciones;
	d = extendedEuclid(a, n, x, y);
	if (b % d == 0) {
		x = mod(x * (b / d), n);
		for (int i = 0; i < d; i++)
			soluciones.push_back(mod(x + i * (n / d), n));
	}
	return soluciones;
}

// Teorema chino del residuo: caso general, resuelve
// a[i] * x = b[i] MOD m[i] para toda i, solucion unica 
// mod M = lcm(m[i]), no es necesario que m[i] sean coprimos
bool chinese_remainder_theorem (const vi &a, const vi &b, 
	const vi &m, ll &x, ll &M) {
    x = 0; M = 1;
    for (int i = 0; i < a.size(); i++) {
        ll a_ = a[i] * M, b_ = b[i] - a[i] * x, m_ = m[i];
        ll y, t, g = extendedEuclid(a_, m_, y, t);
        if (b_ % g) return false;
        b_ /= g; m_ /= g;
        x += M * (y * b_ % m_);
        M *= m_;
    }
    x = mod(x, M);
    return true;
}

int main() {
	return 0;
}
