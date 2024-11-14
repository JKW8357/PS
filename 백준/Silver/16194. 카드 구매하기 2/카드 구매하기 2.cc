#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int dp[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[0] = 0;
	fill(dp + 1, dp + n + 1, INT_MAX);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i] = min(dp[i], dp[i - j] + arr[j]);

	cout << dp[n] << '\n';
	return 0;
}