#include <bits/stdc++.h>
using namespace std;

int dz[6] = { 0,0,0,0,1,-1 };
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };

char board[35][35][35];
int dis[35][35][35];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int l, r, c;
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;

		queue<tuple<int, int, int>> q;
		int ez, ex, ey;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> board[i][j][k];

					dis[i][j][k] = -1;

					if (board[i][j][k] == 'S') {
						q.push({ i, j, k });
						dis[i][j][k] = 0;
					}

					if (board[i][j][k] == 'E') {
						tuple<int, int, int> escape = { i, j, k };
						tie(ez, ex, ey) = escape;
					}
				}
			}
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int dir = 0; dir < 6; dir++) {
				int curz, curx, cury;
				tie(curz, curx, cury) = cur;
				int nz = curz + dz[dir];
				int nx = curx + dx[dir];
				int ny = cury + dy[dir];

				if (nz < 0 || nz >= l || nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (dis[nz][nx][ny] > 0 || board[nz][nx][ny] == '#') continue;

				dis[nz][nx][ny] = dis[curz][curx][cury] + 1;
				q.push({ nz, nx, ny });
			}
		}

		int ans = dis[ez][ex][ey];
		if (ans != -1) cout << "Escaped in " << ans << " minute(s).\n";
		else cout << "Trapped!\n";
	}

	return 0;
}