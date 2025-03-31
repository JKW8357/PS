#include <bits/stdc++.h>
using namespace std;

int n, m;
const int INF = (int)1e9;
vector<vector<int>> adj;
vector<tuple<int, int, int>> edges;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	adj.assign(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++) adj[i][i] = 0;

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
		adj[b][a] = min(adj[b][a], c);
		edges.push_back({ a, b, c });
	}

	floyd();

	double minTime = (double)INF;
	for (int st = 1; st <= n; st++) {
		double totalTime = 0;
		for (auto& [u, v, c] : edges)
			totalTime = max(totalTime, (double)(adj[st][u] + adj[st][v] + c) / 2);
		minTime = min(minTime, totalTime);
	}

	cout << fixed << setprecision(1) << minTime << '\n';
	return 0;
}