#include <bits/stdc++.h>
using namespace std;

int dp[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	dp[0] = 1;
	for (int i = 1; i <= m; i++) {
		int cmd;
		long long cnt;
		cin >> cmd >> cnt;

		if (cmd == 1) {
			cnt %= n;
			dp[i] = (dp[i - 1] + cnt) % n;
			if (dp[i] == 0) dp[i] = n;
		}
		else if (cmd == 2) {
			cnt %= n;
			dp[i] = (dp[i - 1] - cnt + n) % n;
			if (dp[i] == 0) dp[i] = n;
		}
		else dp[i] = dp[cnt];
	}

	cout << dp[m] << '\n';
	return 0;
}