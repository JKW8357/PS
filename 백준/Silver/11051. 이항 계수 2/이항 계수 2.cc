#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= n; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
	}

	cout << dp[n][k] << '\n';
	return 0;
}