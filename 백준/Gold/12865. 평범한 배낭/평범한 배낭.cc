#include <bits/stdc++.h>
using namespace std;

int w[105];
int v[105];
int dp[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++)
		for (int j = k; j >= 1; j--)
			if (j - w[i] >= 0) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

	cout << dp[k] << '\n';
	return 0;
}