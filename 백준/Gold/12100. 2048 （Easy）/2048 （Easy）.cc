#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
vector<vector<int>> board;

void solve(int depth, const vector<vector<int>>& board) {
	if (depth == 5) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans = max(ans, board[i][j]);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		vector<vector<int>> copiedBoard(board);
		switch (dir) {
		case 0: // 상
			for (int j = 0; j <= n - 1; j++) {
				int pos = 0;
				for (int i = 1; i <= n - 1; i++) {
					if (copiedBoard[i][j] == 0) continue;
					int cur = copiedBoard[i][j];
					copiedBoard[i][j] = 0;
					if (copiedBoard[pos][j] == 0) copiedBoard[pos][j] = cur;
					else if (copiedBoard[pos][j] == cur) copiedBoard[pos++][j] *= 2;
					else copiedBoard[++pos][j] = cur;
				}
			}
			break;

		case 1: // 하
			for (int j = 0; j <= n - 1; j++) {
				int pos = n - 1;
				for (int i = n - 2; i >= 0; i--) {
					if (copiedBoard[i][j] == 0) continue;
					int cur = copiedBoard[i][j];
					copiedBoard[i][j] = 0;
					if (copiedBoard[pos][j] == 0) copiedBoard[pos][j] = cur;
					else if (copiedBoard[pos][j] == cur) copiedBoard[pos--][j] *= 2;
					else copiedBoard[--pos][j] = cur;
				}
			}
			break;

		case 2: // 좌
			for (int i = 0; i <= n - 1; i++) {
				int pos = 0;
				for (int j = 1; j <= n - 1; j++) {
					if (copiedBoard[i][j] == 0) continue;
					int cur = copiedBoard[i][j];
					copiedBoard[i][j] = 0;
					if (copiedBoard[i][pos] == 0) copiedBoard[i][pos] = cur;
					else if (copiedBoard[i][pos] == cur) copiedBoard[i][pos++] *= 2;
					else copiedBoard[i][++pos] = cur;
				}
			}
			break;

		case 3: // 우
			for (int i = 0; i <= n - 1; i++) {
				int pos = n - 1;
				for (int j = n - 2; j >= 0; j--) {
					if (copiedBoard[i][j] == 0) continue;
					int cur = copiedBoard[i][j];
					copiedBoard[i][j] = 0;
					if (copiedBoard[i][pos] == 0) copiedBoard[i][pos] = cur;
					else if (copiedBoard[i][pos] == cur) copiedBoard[i][pos--] *= 2;
					else copiedBoard[i][--pos] = cur;
				}
			}
			break;
		}

		solve(depth + 1, copiedBoard);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	board.resize(n);
	for (int i = 0; i < n; i++) {
		board[i].resize(n);
		for (int j = 0; j < n; j++) cin >> board[i][j];
	}

	solve(0, board);
	cout << ans << '\n';

	return 0;
}