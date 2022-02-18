#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);
 
typedef long long int ll;
int n; 
ll memo[10010];
array<ll,10000> p;

ll dp(int len) {
	if (len == 0) return 0;
	if (memo[len] != -1) return memo[len];
	ll ans = numeric_limits<ll>::min();
	for (int i = 0; i < len; i++)
		ans = max(ans, dp(len - (i + 1)) + p[i]);
	return memo[len] = ans;
}

int main() {
	optimizar_io
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i];
	memset(memo, -1, sizeof(memo));
	cout << dp(n) << "\n";
	return 0;
}
