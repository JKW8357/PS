#include <bits/stdc++.h>
using namespace std;

long long dp[35][35];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j <= i - 1; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}

	cout << dp[n - 1][k - 1] << '\n';
	return 0;
}