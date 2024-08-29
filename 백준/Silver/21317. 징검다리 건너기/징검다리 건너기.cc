#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9

int jump[22][2];
int dp[22][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) cin >> jump[i][0] >> jump[i][1];
	cin >> k;

	for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = MAX;
	dp[1][0] = 0;
	dp[2][0] = jump[1][0];

	for (int i = 3; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][0] + jump[i - 1][0], dp[i - 2][0] + jump[i - 2][1]);
		dp[i][1] = min({ dp[i - 1][1] + jump[i - 1][0], dp[i - 2][1] + jump[i - 2][1], dp[i - 3][0] + k });
	}

	cout << min(dp[n][0], dp[n][1]) << '\n';
	return 0;
}