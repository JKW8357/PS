#include <bits/stdc++.h>
using namespace std;

int n;
int cost[20][20];
int dp[20][1 << 20];

int solve(int depth, int bitmask) {
	if (depth == n) return 0;
	if (dp[depth][bitmask]) return dp[depth][bitmask];

	int minCost = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (bitmask & (1 << i)) continue;
		int newCost = cost[depth][i] + solve(depth + 1, bitmask | (1 << i));
		minCost = min(minCost, newCost);
	}

	return dp[depth][bitmask] = minCost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];

	int ans = solve(0, 0);
	cout << ans << '\n';

	return 0;
}