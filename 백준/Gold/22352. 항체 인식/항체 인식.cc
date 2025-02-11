#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

vector<vector<int>> board, result;
bool vis[35][35];

bool bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	vis[sx][sy] = true;

	int oldColor = board[sx][sy];
	board[sx][sy] = result[sx][sy];

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != oldColor) continue;

			q.push({ nx, ny });
			vis[nx][ny] = true;
			board[nx][ny] = board[x][y];
		}
	}

	return board == result;
}

bool check() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] != result[i][j]) 
				return bfs(i, j);

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	board.assign(n, vector<int>());
	result.assign(n, vector<int>());
	for (int i = 0; i < n; i++) board[i].assign(m, 0);
	for (int i = 0; i < n; i++) result[i].assign(m, 0);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> result[i][j];

	cout << (check() ? "YES\n" : "NO\n");
}