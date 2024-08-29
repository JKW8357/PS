#include <bits/stdc++.h>
using namespace std;

int dp[205][205];
int mod = 1e6 + 7;

void solve(int a, int b, int c, int d) {
	for (int i = a; i <= c; i++)
		for (int j = b; j <= d; j++)
			if (!(i == a && j == b)) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w, h, x, y;
	cin >> w >> h >> x >> y;

	dp[1][1] = 1;
	solve(1, 1, x, y);
	solve(x, y, w, h);

	cout << dp[w][h] << '\n';
	return 0;
}