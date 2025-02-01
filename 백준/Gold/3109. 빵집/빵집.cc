#include <bits/stdc++.h>
using namespace std;

int r, c;
string board[10005];
bool vis[10005][505];

bool dfs(int x, int y) {
	vis[x][y] = true;
	if (y == 0) return true;

	for (int nx : {x - 1, x, x + 1}) {
		if (nx < 0 || nx >= r) continue;
		if (vis[nx][y - 1] || board[nx][y - 1] == 'x') continue;
		if (dfs(nx, y - 1)) return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> board[i];

	int ans = 0;
	for (int i = 0; i < r; i++)
		if (dfs(i, c - 1)) ans++;

	cout << ans << '\n';
	return 0;
}