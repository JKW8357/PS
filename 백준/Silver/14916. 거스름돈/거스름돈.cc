#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	fill(dp + 1, dp + n + 1, -1);
	dp[2] = 1;
	dp[4] = 2;
	dp[5] = 1;

	for (int i = 6; i <= n; i++) {
		if (dp[i - 2] != -1 && dp[i - 5] != -1) dp[i] = min(dp[i - 2], dp[i - 5]) + 1;
		else if (dp[i - 2] != -1) dp[i] = dp[i - 2] + 1;
		else if (dp[i - 5] != -1) dp[i] = dp[i - 5] + 1;
	}

	cout << dp[n] << '\n';
	return 0;
}