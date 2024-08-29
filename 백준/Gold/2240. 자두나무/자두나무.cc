#include <bits/stdc++.h>
using namespace std;

int plum[1005];
int dp[1005][35][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, w;
	cin >> t >> w;
	for (int i = 1; i <= t; i++) cin >> plum[i];

	for (int i = 1; i <= t; i++) {
		if (plum[i] == 1) dp[i][0][1] = dp[i - 1][0][1] + 1;
		for (int j = 1; j <= w; j++) {
			if (i < j) break;
			if (plum[i] == 1) {
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + 1;
				dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]);
			}

			else {
				dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]);
				dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + 1;
			}
		}
	}

	cout << max(dp[t][w][1], dp[t][w][2]) << '\n';
	return 0;
}