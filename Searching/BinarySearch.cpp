#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int lowerbound(vector<ll> &arr, ll x) {
	int left = 0, right = arr.size();
	while (left < right) {
		int mid = (left + right) / 2;
		if (x <= arr[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int upperbound(vector<ll> &arr, ll x) {
	int left = 0, right = arr.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (x >= arr[mid])
            left = mid + 1;
        else 
            right = mid;
    }
    return left;
}

int main() {
	
	int n, q, x;
	vector<ll> a;

	scanf("%d %d", &n, &q);
	a.assign(n, 0);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	while (q--) {
		scanf("%d", &x);
		int idx = lowerbound(a, x);
		if (a[idx] == x)
			printf("%d ", idx + 1);
		else
			printf("-1 ");
	}
	printf("\n");
	return 0;
}
