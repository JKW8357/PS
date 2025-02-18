#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

vector<string> board;
unordered_map<string, int> um;

void dfs(int x, int y, string s) {
	um[s]++;
	if (s.size() == 5) return;
	for (int dir = 0; dir < 8; dir++) {
		int nx = (x + dx[dir] + n) % n;
		int ny = (y + dy[dir] + m) % m;
		dfs(nx, ny, s + board[nx][ny]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	board.resize(n);
	for (int i = 0; i < n; i++) cin >> board[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dfs(i, j, string(1, board[i][j]));

	while (k--) {
		string query; cin >> query;
		cout << um[query] << '\n';
	}

	return 0;
}