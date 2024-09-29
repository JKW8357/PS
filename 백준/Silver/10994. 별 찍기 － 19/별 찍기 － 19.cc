#include <bits/stdc++.h>
using namespace std;

char board[400][400];

void solve(int x, int y, int n) {
	if (n == 1) {
		board[x][y] = '*';
		return;
	}

	int len = n * 4 - 3;
	for (int i = 0; i < len; i++) {
		board[x][y + i] = '*';
		board[x + len - 1][y + i] = '*';
		board[x + i][y] = '*';
		board[x + i][y + len - 1] = '*';
	}

	solve(x + 2, y + 2, n - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int size = n * 4 - 3;
	for (int i = 0; i < n * 4 - 3; i++)
		fill(board[i], board[i] + n * 4 - 3, ' ');

	solve(0, 0, n);
	for (int i = 0; i < n * 4 - 3; i++)
		cout << board[i] << '\n';

	return 0;
}