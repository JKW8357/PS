#include <bits/stdc++.h>
using namespace std;

int board[9][9];
int row[9], col[9], box[9];

int box_index(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

void solve(int r, int c) {
	if (r == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout << board[i][j];
			cout << '\n';
		}
		exit(0);
	}
	if (c == 9) solve(r + 1, 0);
	if (board[r][c] != 0) {
		solve(r, c + 1);
		return;
	}

	for (int num = 0; num < 9; num++) {
		if (row[r] & (1 << num)) continue;
		if (col[c] & (1 << num)) continue;
		if (box[box_index(r, c)] & (1 << num)) continue;

		row[r] |= (1 << num);
		col[c] |= (1 << num);
		box[box_index(r, c)] |= (1 << num);
		board[r][c] = num + 1;

		solve(r, c + 1);

		row[r] &= ~(1 << num);
		col[c] &= ~(1 << num);
		box[box_index(r, c)] &= ~(1 << num);
		board[r][c] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++) {
		string str; cin >> str;
		for (int j = 0; j < 9; j++)
			board[i][j] = str[j] - '0';
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != 0) {
				int num = board[i][j] - 1;
				row[i] |= (1 << num);
				col[j] |= (1 << num);
				box[box_index(i, j)] |= (1 << num);
			}
		}
	}

	solve(0, 0);

	return 0;
}