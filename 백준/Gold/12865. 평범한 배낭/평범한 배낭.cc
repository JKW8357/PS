#include <bits/stdc++.h>
using namespace std;

int w[105];
int v[105];
int dp[105][100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - w[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k] << '\n';
	return 0;
}