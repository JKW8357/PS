#include <bits/stdc++.h>
using namespace std;

int w, h;
int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
int board[55][55];
bool vis[55][55];

void dfs(int curX, int curY) {
	vis[curX][curY] = true;
	for (int dir = 0; dir < 8; dir++) {
		int nx = curX + dx[dir];
		int ny = curY + dy[dir];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w || vis[nx][ny] || board[nx][ny] == 0) continue;
		dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
				vis[i][j] = false;
			}
		}

		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!vis[i][j] && board[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << '\n';
	}
	
	return 0;
}