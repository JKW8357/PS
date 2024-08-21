#include <bits/stdc++.h>
using namespace std;

int arr[105];
int dp[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];
	fill(dp, dp + k + 1, 10001);

	dp[0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = arr[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
	
	cout << (dp[k] != 10001 ? dp[k] : -1) << '\n';
	return 0;
}