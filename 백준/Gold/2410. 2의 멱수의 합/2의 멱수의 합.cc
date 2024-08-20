#include <bits/stdc++.h>
using namespace std;

int dp[1000005];
int mod = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) dp[i] = (dp[i - 1] + dp[i / 2]) % mod;
		else dp[i] = dp[i - 1];
	}

	cout << dp[n] << '\n';
	return 0;
}