#include <bits/stdc++.h>
using namespace std;

int n;
int cost[20][20];
vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];

	dp.assign(1 << n, (int)1e9);
	dp[0] = 0;

	for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
		int popCount = __builtin_popcount(bitmask);
		for (int i = 0; i < n; i++) {
			if (bitmask & (1 << i)) continue;
			dp[bitmask | (1 << i)] = min(dp[bitmask | (1 << i)], dp[bitmask] + cost[popCount][i]);
		}
	}

	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}