#include <bits/stdc++.h>
using namespace std;

int board[505][505];
pair<int, int> tetrominos[19][4] = {
	// Tetromino 1
	{ {0, 0}, {1, 0}, {2, 0}, {3, 0} },
	{ {0, 0}, {0, 1}, {0, 2}, {0, 3} },

	// Tetromino 2
	{ {0, 0}, {0, 1}, {1, 0}, {1, 1} },

	// Tetromino 3
	{ {0, 0}, {1, 0}, {2, 0}, {2, 1} },
	{ {0, 0}, {0, 1}, {0, 2}, {1, 0} },
	{ {0, 0}, {0, 1}, {1, 1}, {2, 1} },
	{ {1, 0}, {1, 1}, {1, 2}, {0, 2} },
	{ {2, 0}, {0, 1}, {1, 1}, {2, 1} },
	{ {1, 0}, {1, 1}, {1, 2}, {0, 0} },
	{ {0, 0}, {1, 0}, {2, 0}, {0, 1} },
	{ {0, 0}, {0, 1}, {0, 2}, {1, 2} },

	// Tetromino 4
	{ {0, 0}, {1, 0}, {1, 1}, {2, 1} },
	{ {0, 1}, {1, 0}, {1, 1}, {2, 0} },
	{ {0, 0}, {0, 1}, {1, 1}, {1, 2} },
	{ {0, 1}, {0, 2}, {1, 0}, {1, 1} },

	// Tetromino 5
	{ {0, 0}, {0, 1}, {0, 2}, {1, 1} },
	{ {0, 1}, {1, 0}, {1, 1}, {1, 2} },
	{ {1, 0}, {0, 1}, {1, 1}, {2, 1} },
	{ {0, 0}, {1, 0}, {2, 0}, {1, 1} }
};

int tetrominoSum(int x, int y, int type) {
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += board[tetrominos[type][i].first + x][tetrominos[type][i].second + y];
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < 19; k++)
				ans = max(ans, tetrominoSum(i, j, k));

	cout << ans << '\n';
	return 0;
}