#include <bits/stdc++.h>
using namespace std;

int r, c;
int ans = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

string board[20];
int dis[20][20];
bool alphabet[26];

void dfs(int x, int y) {
	ans = max(ans, dis[x][y]);
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (dis[nx][ny] != 0 || alphabet[board[nx][ny] - 'A']) continue;
		dis[nx][ny] = dis[x][y] + 1;
		alphabet[board[nx][ny] - 'A'] = true;
		dfs(nx, ny);
		dis[nx][ny] = 0;
		alphabet[board[nx][ny] - 'A'] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> board[i];

	dis[0][0] = 1;
	alphabet[board[0][0] - 'A'] = true;
	dfs(0, 0);

	cout << ans << '\n';
	return 0;
}