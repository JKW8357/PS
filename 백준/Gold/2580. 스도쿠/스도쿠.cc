#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool solved = false;
int arr[10][10];
vector<pair<int, int>> blanks;

bool check(int row, int col, int num) {
	for (int i = 0; i < 9; i++)
		if (arr[i][col] == num && i != row) return false;

	for (int j = 0; j < 9; j++)
		if (arr[row][j] == num && j != col) return false;

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (arr[i][j] == num && (i / 3 == row / 3) && (j / 3 == col / 3) && !(i == row && j == col)) return false;

	return true;
}

void solve(int n, int depth) {
	if (depth == n) {
		if (!solved) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++)
					cout << arr[i][j] << ' ';
				cout << '\n';
			}
			solved = true;
		}
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (solved) return;
		arr[blanks[depth].X][blanks[depth].Y] = i;
		if (check(blanks[depth].X, blanks[depth].Y, i)) solve(n, depth + 1);
	}

	arr[blanks[depth].X][blanks[depth].Y] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) blanks.push_back({ i, j });
		}
	}

	solve(blanks.size(), 0);
	return 0;
}