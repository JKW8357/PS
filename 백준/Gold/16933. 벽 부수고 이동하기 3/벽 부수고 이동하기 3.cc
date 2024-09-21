#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[1005];
int dis[1005][1005][11][2];

int bfs(int n, int m, int k) {
	queue<tuple<int, int, int, int>> q;
	q.push({ 0, 0, 0, 0 });
	dis[0][0][0][0] = 1;
	
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int curX, curY, broken, time;
		tie(curX, curY, broken, time) = cur;

		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (board[nx][ny] == '0' && dis[nx][ny][broken][1 - time] == -1) {
				q.push({ nx, ny, broken, 1 - time });
				dis[nx][ny][broken][1 - time] = dis[curX][curY][broken][time] + 1;
			}

			else if (board[nx][ny] == '1' && broken < k && dis[nx][ny][broken + 1][1] == -1) {
				if (time == 0) {
					q.push({ nx, ny, broken + 1, 1 - time });
					dis[nx][ny][broken + 1][1 - time] = dis[curX][curY][broken][time] + 1;
				}
				else {
					q.push({ curX, curY, broken, 1 - time });
					dis[curX][curY][broken][1 - time] = dis[curX][curY][broken][time] + 1;
				}
			}
		}
	}
	
	int ans = INT_MAX;
	for (int l = 0; l <= k; l++) {
		if (dis[n - 1][m - 1][l][0] != -1) ans = min(ans, dis[n - 1][m - 1][l][0]);
		if (dis[n - 1][m - 1][l][1] != -1) ans = min(ans, dis[n - 1][m - 1][l][1]);
	}

	return (ans != INT_MAX ? ans : -1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int l = 0; l <= k; l++)
				dis[i][j][l][0] = dis[i][j][l][1] = -1;

	cout << bfs(n, m, k) << '\n';
	return 0;
}