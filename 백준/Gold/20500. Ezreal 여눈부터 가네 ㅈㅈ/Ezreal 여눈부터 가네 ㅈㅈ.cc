#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;
int dp[1520][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	dp[2][0] = 1; dp[2][1] = 1; dp[2][2] = 0;

	for (int i = 3; i <= n; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
	}

	cout << dp[n][0] << '\n';
	return 0;
}