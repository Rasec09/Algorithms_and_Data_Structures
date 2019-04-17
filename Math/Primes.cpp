#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> factor;
typedef vector<ll> vi;

bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
	ll sieveSize = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= sieveSize; i++) {
		if (bs[i]) {
			for (ll j = i * i; j <= sieveSize; j += i)
				bs[j] = 0;
			primes.push_back(i);
		}
	}
}

vector<factor> primeFactors(ll N) {
	vector<factor> factores;
	ll idx = 0, pf = primes[0];
	while (N != 1 && (pf * pf <= N)) {
		ll power = 0;
		while (N % pf == 0) {
			N /= pf;
			power++;
		}
		if (power) 
			factores.push_back(factor(pf, power));
		pf = primes[++idx];
	}
	if (N != 1) factores.push_back(factor(N, 1));
	return factores;
}

ll numDiv(ll N) {
  	ll idx = 0, pf = primes[idx], ans = 1;
  	while (N != 1 && (pf * pf <= N)) {
    	ll power = 0;
    	while (N % pf == 0) { N /= pf; power++; }
    	ans *= (power + 1);
    	pf = primes[++idx];
  	}
 	if (N != 1) ans *= 2;
	return ans;
}

ll sumDiv(ll N) {
	ll idx = 0, pf = primes[idx], ans = 1;
	while (N != 1 && (pf * pf <= N)) {
		ll power = 0;
		while (N % pf == 0) { N /= pf; power++; }
		ans *= (powMod(pf, power + 1) - 1) / (pf - 1);
		pf = primes[++idx];
	}
	if (N != 1) ans *= (powMod(N, 2) - 1) / (N - 1);
	return ans;
}

ll EulerPhi(ll N) {
	ll idx = 0, pf = primes[0], phi = N;
	while (N != 1 && (pf * pf <= N)) {
		if (N % pf == 0) {
			while (N % pf == 0) N /= pf;
			phi -= phi / pf;
		}
		pf = primes[++idx];
	}
	if (N != 1) phi -= phi / N;
	return phi;
}

int main() {
	return 0;
}
