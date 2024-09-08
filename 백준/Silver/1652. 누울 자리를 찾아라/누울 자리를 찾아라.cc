#include <bits/stdc++.h>
using namespace std;

char board[105][105];

int row(int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n - 1; j++) {
			if (board[i][j] == board[i][j + 1] && board[i][j] == '.') {
				if (flag) {
					flag = false;
					cnt++;
				}
			}
			else flag = true;
		}
	}
	return cnt;
}

int col(int n) {
	int cnt = 0;
	for (int j = 0; j < n; j++) {
		bool flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (board[i][j] == board[i + 1][j] && board[i][j] == '.') {
				if (flag) {
					flag = false;
					cnt++;
				}
			}
			else flag = true;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	cout << row(n) << ' ' << col(n) << '\n';
	return 0;
}