#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
const int INF = (int)1e9;
int dp[MX + 5][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int x, y; string s;
		cin >> x >> y >> s;

		int n = (int)s.size();
		fill(&dp[0][0], &dp[0][0] + n * 2, INF);

		if (s[0] != 'J') dp[0][0] = 0;
		if (s[0] != 'C') dp[0][1] = 0;

		for (int i = 1; i <= n - 1; i++) {
			if (s[i] != 'J') dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
			if (s[i] != 'C') dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
		}

		cout << "Case #" << tc << ": " << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
	}

	return 0;
}