#include <bits/stdc++.h>
using namespace std;

int arr[2][100005];
int dp[2][100005]; // dp[i][j]를 골랐을 때의 최댓값

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		dp[0][2] = arr[0][2] + arr[1][1];
		dp[1][2] = arr[1][2] + arr[0][1];

		for (int j = 3; j <= n; j++)
			for (int i = 0; i < 2; i++)
				dp[i][j] = arr[i][j] + max(dp[1 - i][j - 1], max(dp[1 - i][j - 2], dp[i][j - 2]));

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}

	return 0;
}