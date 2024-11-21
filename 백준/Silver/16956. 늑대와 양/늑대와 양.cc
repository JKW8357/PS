#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

string board[505];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> board[i];

	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			if (board[x][y] == 'S') {
				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
					if (board[nx][ny] == 'W') {
						cout << 0 << '\n';
						return 0;
					}
				}
			}
			else if (board[x][y] == '.') board[x][y] = 'D';
		}
	}
	
	cout << 1 << '\n';
	for (int i = 0; i < r; i++) cout << board[i] << '\n';
	return 0;
}