#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;

int dp[505][505];
int sum[505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc; cin >> tc;
	while (tc--) {
		int k; cin >> k;

		for (int i = 1; i <= k; i++)
			fill(dp[i] + 1, dp[i] + k + 1, INF);

		for (int i = 1; i <= k; i++) {
			int file; cin >> file;
			dp[i][i] = 0;
			sum[i] = sum[i - 1] + file;
		}

		for (int i = 1; i <= k - 1; i++)
			for (int j = 1; i + j <= k; j++)
				for (int m = j; m <= i + j - 1; m++)
					dp[j][i + j] = min(dp[j][i + j], dp[j][m] + dp[m + 1][i + j] + sum[i + j] - sum[j - 1]);

		cout << dp[1][k] << '\n';
	}

	return 0;
}