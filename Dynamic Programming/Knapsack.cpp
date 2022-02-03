#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;

int n, W, value[105], weight[105];
ll memo[105][100005];

ll dp(int idx, int remW) {
	if (remW < 0) return -1e9;
	if (idx == n) return 0;
	if (memo[idx][remW] != -1) return memo[idx][remW];
	return memo[idx][remW] = max(dp(idx + 1, remW), dp(idx + 1, remW - weight[idx]) + value[idx]);
}

int main() {
    optimizar_io
    
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];
    memset(memo, -1, sizeof(memo));
    cout << dp(0, W) << "\n";
    return 0;
}
