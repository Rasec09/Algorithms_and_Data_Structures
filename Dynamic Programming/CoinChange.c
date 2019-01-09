#include <stdio.h>
#include <string.h>

int N, M, S[55]; 
long long int memo[55][255];
 
long long int CoinChange(int idx, int value) {
    if (value == 0) return 1;
    if (value < 0 || idx == M) return 0;
    if (memo[idx][value] != -1) return memo[idx][value];
    return memo[idx][value] = CoinChange(idx + 1, value) + CoinChange(idx, value - S[idx]);
}

int main() {
	
	int i;
	memset(memo, -1, sizeof(memo));
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++)
    	scanf("%d", &S[i]);
  	printf("%lld\n", CoinChange(0, N));
	return 0;
}
