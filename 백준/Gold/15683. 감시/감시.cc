#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int ans = INT_MAX;
int board[10][10];
int simulation[10][10];
vector<pair<int, int>> cctvs;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void monitor(int curX, int curY, int dir) {
	int nx = curX + dx[dir];
	int ny = curY + dy[dir];
	if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 6) return;
	simulation[nx][ny] = 1;
	monitor(nx, ny, dir);
}

void solve(int depth) {
	if (depth == cctvs.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (!simulation[i][j] && board[i][j] == 0) cnt++;
		ans = min(ans, cnt);
		return;
	}

	int x = cctvs[depth].X;
	int y = cctvs[depth].Y;

	int turnBack[10][10]; // 주의: 전역 변수로 선언하면 상태 복원이 불가능(각 재귀 호출마다 독립적인 복사본 생성 X)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			turnBack[i][j] = simulation[i][j];

	for (int dir = 0; dir < 4; dir++) {
		if (board[x][y] == 1) {
			monitor(x, y, dir);
		}

		else if (board[x][y] == 2) {
			monitor(x, y, dir);
			monitor(x, y, (dir + 2) % 4);
		}

		else if (board[x][y] == 3) {
			monitor(x, y, dir);
			monitor(x, y, (dir + 1) % 4);
		}

		else if (board[x][y] == 4) {
			monitor(x, y, dir);
			monitor(x, y, (dir + 1) % 4);
			monitor(x, y, (dir + 2) % 4);
		}

		else if (board[x][y] == 5) {
			monitor(x, y, dir);
			monitor(x, y, (dir + 1) % 4);
			monitor(x, y, (dir + 2) % 4);
			monitor(x, y, (dir + 3) % 4);
		}

		solve(depth + 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				simulation[i][j] = turnBack[i][j];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5) cctvs.push_back({ i, j });
		}
	}

	solve(0);
	cout << ans << '\n';
	return 0;
}