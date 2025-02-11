#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
int board[305][305];
bool vis[305][305];

bool dfs(int x, int y) {
	vis[x][y] = true;
	if (x == m - 1 && y == n - 1) return true;

	for (int dir = 0; dir < 2; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (board[nx][ny] == 0 || vis[nx][ny]) continue;
		if (dfs(nx, ny)) return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	cout << (dfs(0, 0) ? "Yes\n" : "No\n");
	return 0;
}