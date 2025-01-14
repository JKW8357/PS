#include <bits/stdc++.h>
using namespace std;

int r, c;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[20][20];

int solve(int x, int y, int state) {
	int result = 1;
	state |= (1 << board[x][y]);

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (!(state & (1 << board[nx][ny]))) {
			result = max(result, 1 + solve(nx, ny, state));
			if (result == 26) break;
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			char ch; cin >> ch;
			board[i][j] = ch - 'A';
		}
	} 

	int ans = solve(0, 0, 0);
	cout << ans << '\n';

	return 0;
}