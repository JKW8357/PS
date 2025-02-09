#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int ans = -1;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[10][10];
int outbreak[10][10];
vector<pair<int, int>> blanks;
vector<pair<int, int>> virus;

int bfs() {
	queue<pair<int, int>> q;
	for (auto &v : virus) {
		q.push({ v.X, v.Y });
		outbreak[v.X][v.Y] = 2;
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || outbreak[nx][ny] != 0) continue;
			q.push({ nx, ny });
			outbreak[nx][ny] = 2;
		}
	}

	int safeZones = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (outbreak[i][j] == 0) safeZones++;

	return safeZones;
}

void solve() {
	int blanksCount = blanks.size();
	for (int i = 0; i < blanksCount - 2; i++) {
		for (int j = i + 1; j < blanksCount - 1; j++) {
			for (int k = j + 1; k < blanksCount; k++) {
				for (int i = 0; i < n; i++)
					for (int j = 0; j < m; j++)
						outbreak[i][j] = board[i][j];

				outbreak[blanks[i].X][blanks[i].Y] = 1;
				outbreak[blanks[j].X][blanks[j].Y] = 1;
				outbreak[blanks[k].X][blanks[k].Y] = 1;

				ans = max(ans, bfs());
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) blanks.push_back({ i,j });
			if (board[i][j] == 2) virus.push_back({ i,j });
		}
	}

	solve();
	cout << ans << '\n';
	return 0;
}