#include <bits/stdc++.h>
using namespace std;

long long dp[100005][4];
long long mod = 1e9 + 9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % mod;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % mod;
	}

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		cout << accumulate(dp[n] + 1, dp[n] + 4, 0LL) % mod << '\n';
	}

	return 0;
}