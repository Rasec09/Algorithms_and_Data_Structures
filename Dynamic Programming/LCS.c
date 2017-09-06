#include <stdio.h>
#include <string.h>

int LCS[1010][1010];

int max(int a, int b) {
	return (a > b) ? a : b;
}

int main() {
	
	int i, j, n, m;
	char A[1010], B[1010];

	scanf("%s %s", A, B);
	n = strlen(A);
	m = strlen(B);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (A[i - 1] == B[j - 1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}
	printf("%d\n", LCS[n][m]);
	return 0;
}
