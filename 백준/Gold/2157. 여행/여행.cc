#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[305];
int dp[305][305]; // dp[i][j] : i번째 도시에 도착할 때까지 총 j개의 도시를 거쳐서 먹은 기내식 점수 w의 합의 최댓값

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	while (k--) {
		int u, v, w;
		cin >> u >> v >> w;
		if (u < v) adj[u].push_back({ v, w });
	}

	// 도달할 수 없는 경로는 -1로 설정
	for (int i = 0; i <= n; i++)
		fill(dp[i], dp[i] + m + 1, -1);

	dp[1][1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (dp[i][j] == -1) continue;
			for (auto nxt : adj[i])
				dp[nxt.first][j + 1] = max(dp[nxt.first][j + 1], dp[i][j] + nxt.second);
		}
	}
	
	cout << *max_element(dp[n] + 2, dp[n] + m + 1) << '\n';
	return 0;
}