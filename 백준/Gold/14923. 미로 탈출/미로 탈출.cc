#include <bits/stdc++.h>
using namespace std;

int n, m;
int hx, hy;
int ex, ey;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[1005][1005];
int dis[1005][1005][2];

int bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ hx, hy, 0 });
	dis[hx][hy][0] = 0;

	while (!q.empty()) {
		auto [x, y, broken] = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;

			if (board[nx][ny] == 0 && dis[nx][ny][broken] == -1) {
				q.push({ nx, ny, broken });
				dis[nx][ny][broken] = dis[x][y][broken] + 1;
			}

			else if (board[nx][ny] == 1 && broken == 0 && dis[nx][ny][broken + 1] == -1) {
				q.push({ nx, ny, broken + 1 });
				dis[nx][ny][broken + 1] = dis[x][y][broken] + 1;
			}
		}
	}

	if (dis[ex][ey][0] == -1 || dis[ex][ey][1] == -1)
		return max(dis[ex][ey][0], dis[ex][ey][1]);
	else return min(dis[ex][ey][0], dis[ex][ey][1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	cin >> hx >> hy;
	cin >> ex >> ey;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dis[i][j][0] = dis[i][j][1] = -1;

	int ans = bfs();
	cout << ans << '\n';

	return 0;
}