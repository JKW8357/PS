#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int dis[1005][1005];

vector<pair<pair<int, int>, int>> houses;
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r, c;
	cin >> n >> m >> r >> c;

	for (int i = 1; i <= n; i++)
		fill(dis[i], dis[i] + m + 1, -1);

	for (int i = 1; i <= r; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		houses.push_back({ { x, y }, z });
	}

	for (int i = 1; i <= c; i++) {
		int x, y;
		cin >> x >> y;
		dis[x][y] = 0;
		q.push({ x,y });
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (dis[nx][ny] != -1) continue;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	int ans = INT_MAX;
	for (auto h : houses) ans = min(ans, dis[h.first.X][h.first.Y] * h.second);
	cout << ans << '\n';

	return 0;
}