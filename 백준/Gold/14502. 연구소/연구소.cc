#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int ans = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int board[10][10];
int outbreak[10][10];
vector<pair<int, int>> blanks;
vector<pair<int, int>> virus;

int bfs() {
	queue<pair<int, int>> q;
	for (auto &v : virus) {
		q.push({ v.X, v.Y });
		outbreak[v.X][v.Y] = 2;
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || outbreak[nx][ny] != 0) continue;
			q.push({ nx, ny });
			outbreak[nx][ny] = 2;
		}
	}

	int safeZones = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (outbreak[i][j] == 0) safeZones++;

	return safeZones;
}

void preprocess() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			outbreak[i][j] = board[i][j];
}

void solve() {
	int blanksCount = blanks.size();

	// next_permutation(): 초기값은 사전순에서 가장 작은 순열으로 설정: false(0) -> true(1)
	vector<bool> isWall(blanksCount, true);
	fill(isWall.begin(), isWall.end() - 3, false);

	do {
		preprocess();
		for (int i = 0; i < isWall.size(); i++)
			if (isWall[i]) outbreak[blanks[i].X][blanks[i].Y] = 1;
		ans = max(ans, bfs());
	} while (next_permutation(isWall.begin(), isWall.end()));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) blanks.push_back({ i,j });
			if (board[i][j] == 2) virus.push_back({ i,j });
		}
	}

	solve();
	cout << ans << '\n';
	return 0;
}
