#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
int board[12][12];

bool check(int cnt) {
	if (cnt == 1) return true;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (board[x][y] != 2) continue;

			for (int dir = 0; dir < 8; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				int nnx = x + 2 * dx[dir];
				int nny = y + 2 * dy[dir];

				if (nnx < 0 || nnx >= n || nny < 0 || nny >= n) continue;
				if (board[nx][ny] != 2 || board[nnx][nny] != 0) continue;

				board[x][y] = 0;
				board[nx][ny] = 0;
				board[nnx][nny] = 2;

				if (check(cnt - 1)) return true;

				board[x][y] = 2;
				board[nx][ny] = 2;
				board[nnx][nny] = 0;
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) cnt++;
		}
	}

	cout << (check(cnt) ? "Possible" : "Impossible") << '\n';
	return 0;
}