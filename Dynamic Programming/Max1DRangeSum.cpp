#include <bits/stdc++.h>
using namespace std;

long long int A[1000010];

long long int Max1DRangeSum(int N) {

    long long int currSum, ans;
    currSum = ans = A[0];
    for (int i = 1; i < N; i++) {
        if (currSum + A[i] > A[i])
            currSum += A[i];
        else
            currSum = A[i];
        ans = max(ans, currSum);
    }
    return ans;
}

int main() {

    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);
    printf("%lld\n", Max1DRangeSum(N));
    return 0;
}
