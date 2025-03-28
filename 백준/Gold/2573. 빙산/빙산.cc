#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<bool>> vis;
vector<vector<int>> board;

void melt() {
	vector<vector<int>> newBoard(board);
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (board[x][y] == 0) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == 0) newBoard[x][y] = max(newBoard[x][y] - 1, 0);
			}
		}
	}
	board = move(newBoard);
}

void bfs(int sx, int sy) {
	queue<pii> q;
	q.push({ sx, sy });
	vis[sx][sy] = true;

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny]) continue;
			if (board[nx][ny] != 0) {
				q.push({ nx, ny });
				vis[nx][ny] = true;
			}
		}
	}
}

int icebergCount() {
	int result = 0;
	vis.assign(n, vector<bool>(m, false));
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (!vis[x][y] && board[x][y] != 0) {
				result++;
				bfs(x, y);
			}
		}
	}
	return result;
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

	int t = 0, cnt;
	while ((cnt = icebergCount()) == 1) {
		melt();
		t++;
	}

	cout << (cnt >= 2 ? t : 0) << '\n';
	return 0;
}