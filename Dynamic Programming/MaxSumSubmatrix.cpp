#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

int Max1DRangeSum(vector<int> &A, int N) {
    int currSum, ans;
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

int maxSumSubmatrix(vector<vector<int>> &A) {
	int n = A.size();
	int m = A[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (j) A[i][j] += A[i][j - 1];
	}
	int ans = numeric_limits<int>::min();
	for (int l = 0; l < m; l++) {
		for (int r = l; r < m; r++) {
			vector<int> acum(n, 0);
			for (int row = 0; row < n; row++) {
				acum[row] = A[row][r] - (l == 0 ? 0 : A[row][l - 1]);
			}
			int sum = Max1DRangeSum(acum, acum.size());
			ans = max(ans, sum);
		}
	}
	return ans;
}

int main() {
	optimizar_io
	int n;
	vector<vector<int>> A;

	cin >> n;
	A.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
	cout << maxSumSubmatrix(A) << "\n";
	return 0;
}
