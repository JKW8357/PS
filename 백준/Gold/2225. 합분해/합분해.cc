#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9;
int dp[205][205];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= k; i++) dp[0][i] = 1;
	for (int i = 0; i <= n; i++) dp[i][1] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= k; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;

	cout << dp[n][k] << '\n';
	return 0;
}