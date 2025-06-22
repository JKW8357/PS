#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
const int MX = 16;

int n;
int cost[MX][MX];
int dp[1 << MX][MX];

int tsp(int state, int cur) {
	if (state == (1 << n) - 1) return cost[cur][0] > 0 ? cost[cur][0] : INF;
	if (dp[state][cur] != -1) return dp[state][cur];

	dp[state][cur] = INF;
	for (int nxt = 0; nxt < n; nxt++) {
		if (state & (1 << nxt)) continue;
		if (cost[cur][nxt] == 0) continue;
		dp[state][cur] = min(dp[state][cur], tsp(state | (1 << nxt), nxt) + cost[cur][nxt]);
	}

	return dp[state][cur];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];

	fill(&dp[0][0], &dp[0][0] + (1 << n) * MX, -1);
	cout << tsp(1, 0) << '\n';

	return 0;
}