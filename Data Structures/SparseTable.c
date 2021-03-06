#include <stdio.h>
#define MAXN 1000010
#define LOGN 20

int A[MAXN];
int sparse[MAXN][LOGN];
int logs[MAXN];

void preprocess(int n) {
	
	int i, j;

	for (i = 2; i <= n; i++)
		logs[i] = logs[i >> 1] + 1;

	for (i = 0; i < n; i++)
		sparse[i][0] = i;

	for (j = 1; (1 << j) <= n; j++) {
		for (i = 0; i + (1 << j) - 1 < n; i++) {
			int x = sparse[i][j - 1];
			int y = sparse[i + (1 << (j - 1))][j - 1];
			sparse[i][j] = (A[x] <= A[y]) ? x : y;
		}
	}
}

int rmq(int i, int j) {
	int k = logs[j - i + 1];
	int x = sparse[i][k];
	int y = sparse[j - (1 << k) + 1][k];
	return A[x] <= A[y] ? x : y;
}

int main() {
	
	int n, q, i, l, r;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	preprocess(n);
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &l, &r);
		printf("%d\n", A[rmq(l, r)]);
	}
	return 0;
}
