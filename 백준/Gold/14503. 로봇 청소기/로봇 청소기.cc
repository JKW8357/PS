#include <bits/stdc++.h>
using namespace std;

int n, m;
int r, c, d;
int ans = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int board[55][55];

int cleaning() {
	int curX = r, curY = c, dir = d;

	while (true) {
		if (board[curX][curY] == 0) {
			board[curX][curY] = 2;
			ans++;
		}

		bool allcleaned = true;
		for (int w = 0; w < 4; w++) {
			int nx = curX + dx[w];
			int ny = curY + dy[w];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 1) continue;
			if (board[nx][ny] == 0) allcleaned = false;
		}

		if (allcleaned) {
			int nx = curX - dx[dir];
			int ny = curY - dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 1) return ans;
			else {
				curX = nx;
				curY = ny;
				continue;
			}
		}

		dir = (dir + 3) % 4;
		int nx = curX + dx[dir];
		int ny = curY + dy[dir];
		if (board[nx][ny] == 0) {
			curX = nx;
			curY = ny;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	cout << cleaning() << '\n';
	return 0;
}