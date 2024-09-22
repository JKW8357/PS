#include <bits/stdc++.h>
using namespace std;

int board[1005][1005];
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		for (int j = 1; j <= m; j++) board[i][j] = str[j - 1] - '0';
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 1) dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans * ans << '\n';
	return 0;
}