#include <bits/stdc++.h>
using namespace std;

int A[1010], memo[1010];

/*Longest Increasing Subsequence - Top-Down*/
int LIS(int i) {
	
	if (i == 0) 
		return 1;

	if (memo[i] != 0)
		return memo[i];

	int ans = 1;
	for (int j = 0; j < i; j++)
		if (A[i] > A[j])
			ans = max(ans, 1 + LIS(j));
	
	return memo[i] = ans;
}

/*Longest Increasing Subsequence - Bottom-Up*/
int lis(int N) {

	int L[N + 1], res;

	for (int i = 0; i < N; i++) {
		int ans = 1;
		for (int j = 0; j < i; j++)
			if (A[i] > A[j])
				ans = max(ans, 1 + L[j]);
		L[i] = ans;
	}

	res = 0;
	for (int i = 0; i < N; ++i) {
		res = max(res, L[i]);
	}
	return res;
}

int main() {
	
	int T, N, res;

	scanf("%d", &T);
	while (T--) {
		memset(memo, 0, sizeof(memo));
		scanf("%d", &N);
		for (int i = 0; i < N; i++) 
			scanf("%d", &A[i]);

		/*res = 0;
		for (int i = 0; i < N; i++)
			res = max(res, LIS(i));
		printf("%d\n", res);*/

		printf("%d\n", lis(N));
	}
	return 0;
}
