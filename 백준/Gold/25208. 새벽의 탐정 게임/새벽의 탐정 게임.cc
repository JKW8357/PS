#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tup;

int n, m;
int sx, sy;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string board[505];
int dis[505][505][6];
string rollDice[4] = {
	"312504",
	"150342",
	"412053",
	"205341"
};

int bfs(int sx, int sy) {
	queue<tup> q;
	q.push({ sx, sy, 0 });
	dis[sx][sy][0] = 0;
	while (!q.empty()) {
		auto [x, y, j] = q.front(); q.pop();
		if (board[x][y] == 'R') {
			if (j == 0) return dis[x][y][j];
			continue;
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nj = rollDice[dir][j] - '0';
			if (nx < 1 || nx >= n - 1 || ny < 1 || ny >= m - 1) continue;
			if (dis[nx][ny][nj] != -1 || board[nx][ny] == '#') continue;
			q.push({ nx, ny, nj });
			dis[nx][ny][nj] = dis[x][y][j] + 1;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			for (int k = 0; k < 6; k++) dis[i][j][k] = -1;
			if (board[i][j] == 'D') { sx = i; sy = j; }
		}
	}

	int ans = bfs(sx, sy);
	cout << ans << '\n';

	return 0;
}