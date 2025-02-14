#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int shark = 17;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

vector<vector<pii>> board;
vector<pii> coord;

bool oob(int x, int y) { return x < 0 || x >= 4 || y < 0 || y >= 4; }

int maximumEat(vector<vector<pii>> board, vector<pii> coord) {
	for (int num = 1; num <= 16; num++) {
		auto [x, y] = coord[num];
		if (x == -1 || y == -1) continue;

		int dir = board[x][y].second;
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		while ((oob(nx, ny) || board[nx][ny].first == shark)) {
			dir = (dir + 1) % 8;
			nx = x + dx[dir];
			ny = y + dy[dir];
		}
		board[x][y].second = dir;
		int nnum = board[nx][ny].first;

		swap(board[x][y], board[nx][ny]);
		if (nnum != 0) swap(coord[num], coord[nnum]);
		else coord[num] = { nx, ny };
	}

	int result = 0;
	auto [sx, sy] = coord[shark];
	int sdir = board[sx][sy].second;
	for (int i = 1; i <= 3; i++) {
		int nx = sx + i * dx[sdir];
		int ny = sy + i * dy[sdir];
		if (oob(nx, ny) || !board[nx][ny].first) continue;
		
		auto nxtBoard(board);
		auto nxtCoord(coord);

		int eat = nxtBoard[nx][ny].first;
		nxtCoord[eat] = { -1, -1 };
		nxtCoord[shark] = { nx, ny };
		nxtBoard[sx][sy].first = 0;
		nxtBoard[nx][ny].first = shark;

		result = max(result, eat + maximumEat(nxtBoard, nxtCoord));
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	coord.resize(18);
	board.resize(4);
	for (int i = 0; i < 4; i++) {
		board[i].resize(4);
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			board[i][j] = { num, dir - 1 };
			coord[num] = { i, j };
		}
	}

	int firstEat = board[0][0].first;
	board[0][0].first = shark;
	coord[firstEat] = { -1, -1 };
	coord[shark] = { 0, 0 };

	int ans = firstEat + maximumEat(board, coord);
	cout << ans << '\n';

	return 0;
}