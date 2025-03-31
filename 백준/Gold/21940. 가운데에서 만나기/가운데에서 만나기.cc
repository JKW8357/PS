#include <bits/stdc++.h>
using namespace std;

int n, m, k;
const int INF = (int)1e9;
vector<vector<int>> adj;

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

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}

	floyd();

	int k; cin >> k;
	vector<int> ci(k + 1, 0);
	for (int i = 1; i <= k; i++) cin >> ci[i];

	vector<int> ans(n + 1, INF);
	for (int s = 1; s <= n; s++) {
		int d = 0;
		for (int e = 1; e <= k; e++)
			d = max(d, adj[s][ci[e]] + adj[ci[e]][s]);
		ans[s] = d;
	}
	
	int mn = *min_element(ans.begin(), ans.end());
	for (int i = 1; i <= n; i++)
		if (ans[i] == mn) cout << i << ' ';

	return 0;
}