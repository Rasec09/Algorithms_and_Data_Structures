#include <stdio.h>
#include <string.h>
#define MAX_N 1000010

char T[MAX_N], P[MAX_N];
int b[MAX_N], n, m;

void kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1;
  	while (i < m) {
    	while (j >= 0 && P[i] != P[j]) j = b[j];
    	i++; j++;
    	b[i] = j;
	}
}

int kmpSearch() {
	int i = 0, j = 0, occu = 0;
  	while (i < n) {
    	while (j >= 0 && T[i] != P[j]) j = b[j];
    	i++; j++;
    	if (j == m) {
      		//printf("P is found at index %d in T\n", i - j);
      		occu++;
      		j = b[j];
		} 
	}
	return occu;
}

int main() {

	int ans;

	scanf("%s %s", P, T);
	n = strlen(T);
	m = strlen(P);
	kmpPreprocess();
	ans = kmpSearch();
	printf("%d\n", ans);
	return 0;
}
