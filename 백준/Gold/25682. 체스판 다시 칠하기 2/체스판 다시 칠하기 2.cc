#include <bits/stdc++.h>
using namespace std;

int n, m, k;
char board[2005][2005];
int sum[2005][2005];

int solve(char first) {
	for (int i = 1; i <= n; i++)
		fill(sum[i] + 1, sum[i] + m + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			if ((i + j) % 2 != 0 && board[i][j] == first) sum[i][j]++;
			else if ((i + j) % 2 == 0 && board[i][j] != first) sum[i][j]++;
		}
	}

	int res = INT_MAX;
	for (int i = 1; i <= n - k + 1; i++) {
		for (int j = 1; j <= m - k + 1; j++) {
			int total = sum[i + k - 1][j + k - 1]
				- sum[i - 1][j + k - 1]
				- sum[i + k - 1][j - 1]
				+ sum[i - 1][j - 1];
			res = min(res, total);
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	cout << min(solve('B'), solve('W')) << '\n';
	return 0;
}