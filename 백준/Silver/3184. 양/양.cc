#include <bits/stdc++.h>
using namespace std;

int r, c;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0,-1 };

string board[255];
bool vis[255][255];

int sheep = 0;
int wolves = 0;

void dfs(int x, int y, int& s, int& w) {
	vis[x][y] = true;
	if (board[x][y] == 'o') s++;
	if (board[x][y] == 'v') w++;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (vis[nx][ny] || board[nx][ny] == '#') continue;
		dfs(nx, ny, s, w);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> board[i];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!vis[i][j] && (board[i][j] == 'o' || board[i][j] == 'v')) {
				int s = 0, w = 0;
				dfs(i, j, s, w);
				if (s > w) sheep += s;
				else wolves += w;
			}
		}
	}

	cout << sheep << ' ' << wolves << '\n';
	return 0;
}