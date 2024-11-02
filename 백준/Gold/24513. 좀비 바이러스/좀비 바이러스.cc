#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[1005][1005];
bool infectedCurrently[1005][1005];
vector<pair<int, int>> infectedCurrentlyList;
queue<pair<int, int>> v1, v2;

void bfs() {
	while (!v1.empty() || !v2.empty()) {
		int v1Size = v1.size();
		int v2Size = v2.size();

		for (int i = 0; i < v1Size; i++) {
			auto cur = v1.front(); v1.pop();
			if (board[cur.X][cur.Y] == 3) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] != 0) continue;
				v1.push({ nx, ny });
				board[nx][ny] = 1;
				infectedCurrently[nx][ny] = true;
				infectedCurrentlyList.push_back({ nx,ny });
			}
		}

		for (int i = 0; i < v2Size; i++) {
			auto cur = v2.front(); v2.pop();
			if (board[cur.X][cur.Y] == 3) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == 0) {
					v2.push({ nx, ny });
					board[nx][ny] = 2;
				}
				else if (infectedCurrently[nx][ny] && board[nx][ny] == 1) board[nx][ny] = 3;
			}
		}

		for (auto& e : infectedCurrentlyList) infectedCurrently[e.X][e.Y] = false;
		infectedCurrentlyList.clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) v1.push({ i, j });
			else if (board[i][j] == 2) v2.push({ i, j });
		}
	}

	bfs();
	int ans[3] = {};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] > 0) ans[board[i][j] - 1]++;

	for (int i = 0; i < 3; i++) cout << ans[i] << ' ';
	return 0;
}