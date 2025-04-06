#include <bits/stdc++.h>
using namespace std;

int board[1030][1030];

int calc(int x, int y, int n) {
	if (n == 1) return board[x][y];

	int half = n / 2;
	int a = calc(x, y, half);
	int b = calc(x + half, y, half);
	int c = calc(x, y + half, half);
	int d = calc(x + half, y + half, half);

	vector<int> result = { a, b, c, d };
	sort(result.begin(), result.end());
	return result[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	cout << calc(0, 0, n) << '\n';
	return 0;
}