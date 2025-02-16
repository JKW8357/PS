#include <bits/stdc++.h>
using namespace std;

int n, m;
string board[1005];
int state[1005][1005];
int ans = 0;

pair<int, int> moveDir(char c) {
	if (c == 'U') return { -1, 0 };
	else if (c == 'D') return { 1, 0 };
	else if (c == 'L') return { 0, -1 };
	return { 0, 1 };
}

void dfs(int x, int y) {
	state[x][y] = 1;

	auto [dx, dy] = moveDir(board[x][y]);
	int nx = x + dx;
	int ny = y + dy;

	if (state[nx][ny] == 0) dfs(nx, ny);
	else if (state[nx][ny] == 1) ans++;

	state[x][y] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (state[i][j] != 0) continue;
			dfs(i, j);
		}
	}

	cout << ans << '\n';
	return 0;
}