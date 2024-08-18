#include <bits/stdc++.h>
using namespace std;

long long dp[1001][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 9; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i];
		ans %= 10007;
	}

	cout << ans;

	return 0;
}
