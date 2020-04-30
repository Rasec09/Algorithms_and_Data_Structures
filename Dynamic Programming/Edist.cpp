#include <bits/stdc++.h>
using namespace std;

int Edist[2010][2010];

int main() {
	
	int TC, n, m;
	char A[2010], B[2010];

	scanf("%d", &TC);
	while (TC--) {
		scanf("%s %s", A, B);
		n = strlen(A);
		m = strlen(B);

		for (int i = 0; i <= n; i++)
			Edist[i][0] = i;
		
		for (int j = 0; j <= m; j++)
			Edist[0][j] = j;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (A[i - 1] == B[j - 1])
					Edist[i][j] = Edist[i - 1][j - 1];
				else
					Edist[i][j] = 1 + min({Edist[i - 1][j - 1], Edist[i - 1][j], Edist[i][j - 1]});	
			}
		}
		printf("%d\n", Edist[n][m]);
	}
	return 0;
}
