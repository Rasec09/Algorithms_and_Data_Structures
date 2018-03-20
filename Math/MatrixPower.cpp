#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> Vector;
typedef vector<Vector> Matrix;

Matrix multMatrix(Matrix &a, Matrix &b, ll m) {
	Matrix c(a.size(), Vector(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < b.size(); k++) {
				c[i][j] += (a[i][k] % (1 << m)) * (b[k][j] % (1 << m));
				c[i][j] %= (1 << m);
			}
		}
	}
	return c;
}

Matrix matrixPower(Matrix &a, ll n, ll m) {
	Matrix result(a);
	while (n) {
		if (n & 1)
			result = multMatrix(result, a, m);
		a = multMatrix(a, a, m);
		n >>= 1;
	}
	return result;
}

int main() {
	
	int n, m;
	Matrix base(2, Vector(2, 0));

	base[0][0] = 0, base[0][1] = 1;
	base[1][0] = 1, base[1][1] = 1;
	while (scanf("%d %d", &n, &m) != EOF) {
		Matrix fib(base);
		fib = matrixPower(fib, n, m);
		printf("%lld\n", fib[0][0]);
	}
	return 0;
}
