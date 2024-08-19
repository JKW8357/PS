#include <bits/stdc++.h>
using namespace std;

int board[105][105];
long long dp[105][105];

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];

	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 2; k++) {
				if (dp[i][j] == 0 || board[i][j] == 0) continue;
				int nx = i + board[i][j] * dx[k];
				int ny = j + board[i][j] * dy[k];
				if (nx > n || ny > n) continue;
				dp[nx][ny] += dp[i][j];
			}
		}
	}

	cout << dp[n][n] << '\n';
	return 0;
}