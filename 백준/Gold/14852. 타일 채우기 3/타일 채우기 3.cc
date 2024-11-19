#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
ll dp[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 7;
	ll sum = dp[0];

	for (int i = 3; i <= n; i++) {
		dp[i] = (2 * dp[i - 1] + 3 * dp[i - 2] + 2 * sum) % mod;
		sum = (sum + dp[i - 2]) % mod;
	}

	cout << dp[n] << '\n';
	return 0;
}