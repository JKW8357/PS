#include <bits/stdc++.h>
using namespace std;

int dx[8] = { 1,1,1,0,-1,-1,-1,0 };
int dy[8] = { 0,1,-1,1,0,1,-1,-1 };

const int MX = 1000;
string board[MX + 5];
int res[MX + 5][MX + 5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> board[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isdigit(board[i][j])) continue;
			for (int dir = 0; dir < 8; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				res[nx][ny] += board[i][j] - '0';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (isdigit(board[i][j])) cout << '*';
			else if (res[i][j] >= 10) cout << 'M';
			else cout << res[i][j];
		}
		cout << '\n';
	}

	return 0;
}