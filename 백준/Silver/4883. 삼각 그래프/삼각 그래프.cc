#include <bits/stdc++.h>
using namespace std;

int arr[100005][3];
int dp[100005][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				cin >> arr[i][j];

		dp[0][0] = INT_MAX;
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][1] + arr[0][2];

		for (int i = 1; i < n; i++) {
			dp[i][0] = arr[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = arr[i][1] + min({ dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
			dp[i][2] = arr[i][2] + min({ dp[i][1], dp[i - 1][1], dp[i - 1][2] }); // 비용이 음수인 경우도 고려
		}

		cout << k++ << ". " << dp[n - 1][1] << '\n';
	}

	return 0;
}