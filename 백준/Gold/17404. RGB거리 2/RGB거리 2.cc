#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
int arr[1001][4];
int dp[1001][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i][1] >> arr[i][2] >> arr[i][3];

	for (int firstColor = 1; firstColor <= 3; firstColor++) {
		for (int start = 1; start <= 3; start++) {
			if (firstColor == start) dp[1][start] = arr[1][start];
			else dp[1][start] = (int)1e9;
		}

		for (int i = 2; i <= n; i++) {
			dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
			dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][3];
		}

		for (int lastColor = 1; lastColor <= 3; lastColor++)
			if (lastColor != firstColor) ans = min(ans, dp[n][lastColor]);
	}

	cout << ans << '\n';
	return 0;
}