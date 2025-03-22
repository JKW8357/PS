#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
vector<vector<int>> board;
vector<pair<int, int>> clouds;
vector<vector<bool>> rained;

void moveClouds(int dir, int dis) {
	for (auto& [x, y] : clouds) {
		x = (x + dx[dir] * dis + n) % n;
		y = (y + dy[dir] * dis + n) % n;
	}
}

void rainAndAddWater() {
	for (auto& [x, y] : clouds) {
		board[x][y]++;
		rained[x][y] = true;
	}

	for (auto& [x, y] : clouds) {
		for (int dir : {1, 3, 5, 7}) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] > 0) board[x][y]++;
		}
	}

	clouds.clear();
}

void makeClouds() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (board[x][y] >= 2 && !rained[x][y]) {
				clouds.push_back({ x, y });
				board[x][y] -= 2;
			}
		}
	}

	rained.assign(n, vector<bool>(n, false));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	board.assign(n, vector<int>(n, 0));
	rained.assign(n, vector<bool>(n, false));
	clouds = { {n - 1, 0}, {n - 1, 1}, {n - 2, 0}, {n - 2, 1} };

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			cin >> board[x][y];

	while (m--) {
		int dir, dis;
		cin >> dir >> dis;
		moveClouds(--dir, dis % n);
		rainAndAddWater();
		makeClouds();
	}

	int totalWater = 0;
	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			totalWater += board[x][y];

	cout << totalWater << '\n';
	return 0;
}