#include <bits/stdc++.h>
using namespace std;
#define mod (long long)1e9

long long dp[101][10][1 << 10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if (n <= 9) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 1; i <= 9; i++) dp[1][i][1 << i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= (1 << 10) - 1; k++) {
				if (j > 0) {
					dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
					dp[i][j][k | (1 << j)] %= mod;
				}
				if (j < 9) {
					dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
					dp[i][j][k | (1 << j)] %= mod;
				}
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i][(1 << 10) - 1] % mod;
		ans %= mod;
	}
	cout << ans << '\n';

	return 0;
}