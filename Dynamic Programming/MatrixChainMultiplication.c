#include <stdio.h>
#define MAXN 15

int n, p[MAXN], s[MAXN][MAXN];

int MatrixChainOrden() {
	
	int i, j, k, l, q;
	int m[MAXN][MAXN];

	for (i = 1; i <= n; i++)
		m[i][i] = 0;
	for (l = 2; l <= n; l++) {
		for (i = 1; i <= n - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = 1e9;
			for (k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	return m[1][n];
}

void print_solution(int i, int j) {
	if (i == j)
		printf("A%d", i++);
	else {
		printf("(");
		print_solution(i, s[i][j]);
		printf(" x ");
		print_solution(s[i][j] + 1, j);
		printf(")");
	}
}

int main() {
	
	int i, t = 0;

	while (scanf("%d", &n), n) {
		for (i = 0; i < n; i++)
			scanf("%d %d", &p[i], &p[i + 1]);
		MatrixChainOrden();
		printf("Case %d: ", ++t);
		print_solution(1, n);
		printf("\n");
	}
	return 0;
}
