#include <bits/stdc++.h>
using namespace std;

int memory[105];
int cost[105];
int dp[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> memory[i];
	for (int i = 1; i <= n; i++) cin >> cost[i];
	int cost_sum = accumulate(cost + 1, cost + n + 1, 0);

	for (int i = 1; i <= n; i++)
		for (int j = cost_sum; j >= 0; j--)
			if (j - cost[i] >= 0) dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);

	int ans = 0;
	while (dp[ans] < m) ans++;
	cout << ans << '\n';

	return 0;
}