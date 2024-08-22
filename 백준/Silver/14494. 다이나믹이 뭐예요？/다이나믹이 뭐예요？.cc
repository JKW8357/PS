#include <bits/stdc++.h>
using namespace std;

long long dp[1005][1005];
long long mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	dp[1][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] += (dp[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j]) % mod;

	cout << dp[n][m] << '\n';
	return 0;
}