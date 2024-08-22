#include <bits/stdc++.h>
using namespace std;

int jump[200005];
int dp[200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> jump[i];

	fill(dp + 1, dp + n + 1, 1);
	for (int i = n; i >= 1; i--)
		if (i + jump[i] + 1 <= n) dp[i] += dp[i + jump[i] + 1];

	for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
	return 0;
}