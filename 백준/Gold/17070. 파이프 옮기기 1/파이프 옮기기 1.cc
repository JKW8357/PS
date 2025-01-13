#include <bits/stdc++.h>
using namespace std;

int board[16][16];
int dp[16][16][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	dp[0][1][0] = 1;
	for (int j = 2; j < n - 1; j++)
		if (board[0][j] == 0) dp[0][j][0] = dp[0][j - 1][0];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (board[i][j] == 0 && board[i - 1][j] == 0 && board[i][j - 1] == 0)
				dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];

			if (board[i][j] == 0) {
				dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][1];
				dp[i][j][2] += dp[i - 1][j][1] + dp[i - 1][j][2];
			}
		}
	}

	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << '\n';
	return 0;
}