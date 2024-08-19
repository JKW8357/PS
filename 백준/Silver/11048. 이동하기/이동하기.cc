#include <bits/stdc++.h>
using namespace std;

int board[1005][1005];
int dp[1005][1005];

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	dp[1][1] = board[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 2; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx > n || ny > m) continue;
				dp[nx][ny] = max(dp[nx][ny], board[nx][ny] + dp[i][j]);
			}
		}
	}

	cout << dp[n][m] << '\n';
	return 0;
}