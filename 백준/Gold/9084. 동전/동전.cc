#include <bits/stdc++.h>
using namespace std;

int coins[25];
int dp[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> coins[i];
		cin >> m;

		fill(dp, dp + m + 1, 0);
		dp[0] = 1;

		for (int i = 0; i < n; i++)
			for (int j = coins[i]; j <= m; j++)
				dp[j] += dp[j - coins[i]];

		cout << dp[m] << '\n';
	}

	return 0;
}