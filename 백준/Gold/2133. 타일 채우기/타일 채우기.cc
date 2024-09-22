#include <bits/stdc++.h>
using namespace std;

int dp[30];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[2] * dp[i - 2];
		for (int j = i - 4; j >= 0; j -= 2) dp[i] += dp[j] * 2;
	}

	cout << dp[n] << '\n';
	return 0;
}