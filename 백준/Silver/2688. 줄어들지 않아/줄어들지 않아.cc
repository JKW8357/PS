#include <bits/stdc++.h>
using namespace std;

long long dp[65][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			dp[i][0] = 1;
			for (int j = 1; j <= 9; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}

		long long ans = accumulate(dp[n], dp[n] + 10, 0LL);
		cout << ans << '\n';
	}

	return 0;
}