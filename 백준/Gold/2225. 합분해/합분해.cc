#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9;
int dp[205][205];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= k; i++) dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			for (int x = 0; x <= i; x++)
				dp[i][j] = (dp[i][j] + dp[i - x][j - 1]) % mod;

	cout << dp[n][k] << '\n';
	return 0;
}