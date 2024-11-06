#include <bits/stdc++.h>
using namespace std;

string board[70];

bool allSame(int x, int y, int n) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[i][j] != board[x][y]) return false;
	return true;
}

void solve(int x, int y, int n) {
	if (allSame(x, y, n)) {
		cout << board[x][y];
		return;
	}

	cout << '(';
	int half = n / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			solve(x + i * half, y + j * half, half);
	cout << ')';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> board[i];
	solve(0, 0, n);

	return 0;
}