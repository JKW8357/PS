#include <bits/stdc++.h>
using namespace std;

int a[105];
int b[105];
vector<vector<char>> board;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> a[i] >> b[i];
	board.assign(n, vector<char>(m, '\0'));

	int idx = 0;
	for (int j = 0; j < m; j++) {
		int left = n - idx;
		int mxAbsents = n - (a[j] + b[j]);
		if (mxAbsents < 0) {
			cout << "NO" << '\n';
			return 0;
		}
		int absents = min(left, mxAbsents);
		for (int k = 0; k < absents; k++)
			board[idx + k][j] = 'X';
		idx += absents;
	}

	if (idx != n) {
		cout << "NO" << '\n';
		return 0;
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (board[i][j] == 'X') continue;
			if (a[j] > 0) {
				board[i][j] = '+';
				a[j]--;
			}
			else board[i][j] = '-';
		}
	}

	cout << "YES" << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << board[i][j];
		cout << '\n';
	}

	return 0;
}