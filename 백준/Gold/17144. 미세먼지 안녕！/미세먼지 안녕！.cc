#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int topPurifier;
int bottomPurifier;

void diffusion(vector<vector<int>>& board) {
	vector<vector<int>> diffused(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] <= 0) continue;
			int diffusedDust = board[i][j] / 5;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] == -1) continue;
				board[i][j] -= diffusedDust;
				diffused[nx][ny] += diffusedDust;
			}
			
		}
	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			board[i][j] += diffused[i][j];
}

void purifier(vector<vector<int>>& board) {
	for (int x = topPurifier - 1; x > 0; x--) board[x][0] = board[x - 1][0];
	for (int y = 0; y < c - 1; y++) board[0][y] = board[0][y + 1];
	for (int x = 0; x < topPurifier; x++) board[x][c - 1] = board[x + 1][c - 1];
	for (int y = c - 1; y > 1; y--) board[topPurifier][y] = board[topPurifier][y - 1];
	board[topPurifier][1] = 0;

	for (int x = bottomPurifier + 1; x < r - 1; x++) board[x][0] = board[x + 1][0];
	for (int y = 0; y < c - 1; y++) board[r - 1][y] = board[r - 1][y + 1];
	for (int x = r - 1; x > bottomPurifier; x--) board[x][c - 1] = board[x - 1][c - 1];
	for (int y = c - 1; y > 1; y--) board[bottomPurifier][y] = board[bottomPurifier][y - 1];
	board[bottomPurifier][1] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c >> t;
	vector<vector<int>> board(r, vector<int>(c));
	
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j];

	for (int i = 0; i < r; i++) {
		if (board[i][0] == -1) {
			topPurifier = i;
			bottomPurifier = i + 1;
			break;
		}
	}

	while (t--) {
		diffusion(board);
		purifier(board);
	}

	int totalDust = 2;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			totalDust += board[i][j];

	cout << totalDust << '\n';
	return 0;
}