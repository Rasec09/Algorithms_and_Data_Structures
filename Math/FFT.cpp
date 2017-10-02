#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double Double;
typedef complex<Double> complejo;
const int MAXN = 2000010;
int rev[MAXN];
complejo wlen_pw[MAXN];

// Algoritmo de la transformada rapida de Fourier
// se debe de garantizar que n es una potencia de 2
// para calcular la transformada inversa enviar true en la bandera
void FFT(vector<complejo> &a, int n, bool invert) {
	for (int i = 0; i < n; ++i)
		if(i < rev[i])
			swap(a[i], a[rev[i]]);

	for (int len = 2; len <= n; len <<= 1) {
		Double ang = 2 * M_PI / len * ( invert ? - 1 : + 1 );
		int len2 = len >> 1 ;
 
		complejo wlen(cos(ang), sin(ang));
		wlen_pw[0] = complejo(1, 0);
		for (int i = 1; i < len2; ++i)
			wlen_pw[i] = wlen_pw[i - 1] * wlen;
		
		complejo t; int r, l;
		for (int i = 0; i < n; i += len) {
			for (int j = 0; j < len/2; j++) {
				r = i + j + len/2; l = i + j;
				t = a[r] * wlen_pw[j];
				a[r] = a[l] - t;
				a[l] += t;
			}
		}
	}
	if (invert)
		for (int i = 0; i < n; ++i)
			a [i] /= n;
}

void calcRev(int n, int logn) {
	for (int i = 0; i < n; ++i) {
		rev[i] = 0 ;
		for (int j = 0; j < logn; ++j)
			if (i & ( 1 << j ))
				rev[i] |= 1 << (logn - 1 - j);
	}
}

vector<ll> MultiplicaPol(const vector<ll> &a, const vector<ll> &b) {
    int l = max(a.size(), b.size()), logn = 0, n;
    for (n = 1; n < l; n <<= 1) ++logn;
    n <<= 1; ++logn;
    calcRev(n, logn);
 
    vector<complejo> A(n), B(n);
    for (int i = 0; i < a.size(); i++) A[i] = complejo(a[i]);
    for (int i = 0; i < b.size(); i++) B[i] = complejo(b[i]);
 
    FFT(A, n, false);
    FFT(B, n, false);
    for (int i = 0; i < n; i++)
        A[i] *= B[i];
    FFT(A, n, true);
 
    vector<ll> res(n);
    for (int i = 0; i < n; i++)
        res[i] = (ll) roundl(A[i].real());
    return res;
}
 
int main() {
    
    int TC, n;
    vector<ll> a, b, c;
 
    cin >> TC;
    while (TC--) {
        cin >> n;
        a.assign(n + 1, 0);
        b.assign(n + 1, 0);
        for (int i = 0; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i <= n; i++)
            cin >> b[i];
        c = MultiplicaPol(a, b);
        cout << c[0];
        for (int i = 1; i < 2 * n + 1; i++)
            cout << " " << c[i];
        cout << "\n";
    }
    return 0;
}
