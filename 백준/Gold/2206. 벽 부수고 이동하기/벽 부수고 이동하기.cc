#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[1005];
int dis[1005][1005][2];

int bfs(int n, int m) {
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	dis[0][0][0] = 1;
	
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int curX, curY, broken;
		tie(curX, curY, broken) = cur;

		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (board[nx][ny] == '0' && dis[nx][ny][broken] == -1) {
				q.push({ nx, ny, broken });
				dis[nx][ny][broken] = dis[curX][curY][broken] + 1;
			}

			else if (board[nx][ny] == '1' && broken == 0 && dis[nx][ny][broken] == -1) {
				q.push({ nx, ny, broken + 1 });
				dis[nx][ny][broken + 1] = dis[curX][curY][broken] + 1;
			}
		}
	}
	
	if (dis[n - 1][m - 1][0] == -1 || dis[n - 1][m - 1][1] == -1)
		return max(dis[n - 1][m - 1][0], dis[n - 1][m - 1][1]);
	else return min(dis[n - 1][m - 1][0], dis[n - 1][m - 1][1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dis[i][j][0] = dis[i][j][1] = -1;

	cout << bfs(n, m) << '\n';
	return 0;
}