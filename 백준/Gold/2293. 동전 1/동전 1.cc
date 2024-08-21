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
	
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = arr[i]; j <= k; j++)
			dp[j] += dp[j - arr[i]];
	
	cout << dp[k] << '\n';
	return 0;
}