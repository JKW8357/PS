#include <bits/stdc++.h>
using namespace std;

int dx1[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy1[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dx2[4] = { 1,0,-1,0 };
int dy2[4] = { 0,1,0,-1 };

int board[202][202];
int dis[202][202][31];
int k, w, h;

void bfs(int x, int y, int k) {
	queue<tuple<int, int, int>> Q;
	Q.push({ x, y, 0 });
	dis[x][y][0] = 0;

	int cx, cy, jump;
	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front();
		tie(cx, cy, jump) = cur;
		Q.pop();

		if (jump < k) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = cx + dx1[dir];
				int ny = cy + dy1[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (board[nx][ny] == 1) continue;
				if (dis[nx][ny][jump + 1] != -1) continue;
				Q.push({ nx, ny, jump + 1 });
				dis[nx][ny][jump + 1] = dis[cx][cy][jump] + 1;
			}
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cx + dx2[dir];
			int ny = cy + dy2[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (board[nx][ny] == 1) continue;
			if (dis[nx][ny][jump] != -1) continue;
			Q.push({ nx, ny, jump });
			dis[nx][ny][jump] = dis[cx][cy][jump] + 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
			for (int l = 0; l <= k; l++)
				dis[i][j][l] = -1;
		}
	}

	bfs(0, 0, k);
	int ans = INT_MAX;
	for (int i = 0; i <= k; i++)
		if (dis[h - 1][w - 1][i] != -1)
			ans = min(ans, dis[h - 1][w - 1][i]);

	if (ans == INT_MAX) cout << -1;
	else cout << ans;

	return 0;
}