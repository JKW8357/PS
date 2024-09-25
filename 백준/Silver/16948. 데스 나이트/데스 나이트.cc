#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int r1, c1, r2, c2;
int dx[6] = { -2,-2,0,0,2,2 };
int dy[6] = { -1,1,-2,2,-1,1 };
int dis[205][205];

int bfs() {
	queue<pair<int, int>> q;
	q.push({ r1, c1 });
	dis[r1][c1] = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || dis[nx][ny] != -1) continue;
			q.push({ nx, ny });
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			if (nx == r2 && ny == c2) return dis[nx][ny];
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> r1 >> c1 >> r2 >> c2;
	for (int i = 0; i < n; i++)
		fill(dis[i], dis[i] + n, -1);

	int ans = bfs();
	cout << ans << '\n';
	return 0;
}