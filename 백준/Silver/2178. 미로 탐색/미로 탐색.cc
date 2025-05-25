#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[105];
int dis[105][105];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dis[0][0] = 1;
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dis[nx][ny] != -1 || board[nx][ny] == '0') continue;
			q.push({ nx, ny });
			dis[nx][ny] = dis[x][y] + 1;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i = 0; i < n; i++) fill(dis[i], dis[i] + m, -1);
	bfs();

	cout << dis[n - 1][m - 1] << '\n';
    return 0;
}