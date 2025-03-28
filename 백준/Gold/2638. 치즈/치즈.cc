#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<bool>> vis;
vector<vector<int>> board;

void melt() {
	vector<pii> melted;
	vis.assign(n, vector<bool>(m, false));
	queue<pii> q;
	q.push({ 0, 0 });
	q.push({ n - 1, 0 });
	q.push({ 0, m - 1 });
	q.push({ n - 1, m - 1 });
	vis[0][0] = true;
	vis[n - 1][0] = true;
	vis[0][m - 1] = true;
	vis[n - 1][m - 1] = true;

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny]) continue;
			if (board[nx][ny] == 0) {
				q.push({ nx, ny });
				vis[nx][ny] = true;
			}
			else {
				int outerCnt = 0;
				for (int dir2 = 0; dir2 < 4; dir2++) {
					int nnx = nx + dx[dir2];
					int nny = ny + dy[dir2];
					if (nnx < 0 || nnx >= n || nny < 0 || nny >= m) continue;
					if (vis[nnx][nny] && board[nnx][nny] == 0) outerCnt++;
				}
				if (outerCnt >= 2) melted.push_back({ nx, ny });
			}
		}
	}
	for (auto& [x, y] : melted) board[x][y] = 0;
}

bool all_melted() {
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			if (board[x][y] == 1) return false;
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	board.assign(n, vector<int>(m));
	vis.assign(n, vector<bool>(m, false));
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
			cin >> board[x][y];

	int t = 0;
	while (!all_melted()) { melt(); t++; }
	cout << t << '\n';

	return 0;
}