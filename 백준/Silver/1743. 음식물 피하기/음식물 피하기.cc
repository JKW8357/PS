#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int cnt = 0;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int board[105][105];
bool vis[105][105];

void dfs(int x, int y) {
	vis[x][y] = true; cnt++;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
		if (board[nx][ny] == 0 || vis[nx][ny]) continue;
		dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	
	while (k--) {
		int r, c;
		cin >> r >> c;
		board[r][c] = 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 1 && !vis[i][j]) {
				cnt = 0;
				dfs(i, j);
				ans = max(ans, cnt);
			}
		}
	}

	cout << ans << '\n';
	return 0;
}