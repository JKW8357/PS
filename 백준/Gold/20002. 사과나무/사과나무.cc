#include <bits/stdc++.h>
using namespace std;

int board[305][305];
int sum[305][305];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum[i][j] = board[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

	int ans = INT_MIN;
	for (int k = 1; k <= n; k++)
		for (int i = k; i <= n; i++)
			for (int j = k; j <= n; j++)
				ans = max(ans, sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k]);

	cout << ans << '\n';
	return 0;
}