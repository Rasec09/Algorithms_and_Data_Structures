//Suma de todos los digitos de los numeros en el rango [A,B]
#include <stdio.h>
#include <string.h>

typedef long long int ll;
int numSize;
ll memo[20][2][165];
char num[20];

ll dp(int pos, int small, ll sum) {
    if (pos == numSize) return sum;
    if (memo[pos][small][sum] != -1) return memo[pos][small][sum];

    ll ans = 0;
    int d, limit = (small ? 9 : num[pos] - 48);
    for (d = 0; d <= limit; d++) {
        if (d < limit)
            ans += dp(pos + 1, 1, sum + d);
        else
            ans += dp(pos + 1, small, sum + d);
    }
    return memo[pos][small][sum] = ans;
}

ll count(ll n) {    
    sprintf(num, "%lld", n);
    numSize = strlen(num);
    memset(memo, -1, sizeof(memo));
    return dp(0, 0, 0);
}

int main() {
    int TC;
    ll A, B;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%lld %lld", &A, &B);
        printf("%lld\n", (A <= 1 ? count(B) : count(B) - count(A - 1)));
    }
    return 0;
}
