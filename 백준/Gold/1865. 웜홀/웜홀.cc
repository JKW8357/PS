#include <bits/stdc++.h>
using namespace std;

int n, m, w;
const int INF = (int)1e9;
vector<vector<int>> adj;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> m >> w;
		adj.assign(n + 1, vector<int>(n + 1, INF));
		for (int i = 1; i <= n; i++) adj[i][i] = 0;

		while (m--) {
			int s, e, t;
			cin >> s >> e >> t;
			if (adj[s][e] > t) {
				adj[s][e] = t;
				adj[e][s] = t;
			}
		}

		while (w--) {
			int s, e, t;
			cin >> s >> e >> t;
			if (adj[s][e] > -t) adj[s][e] = -t;
		}

		floyd();

		bool foundNegativeCycle = false;
		for (int i = 1; i <= n; i++) {
			if (adj[i][i] < 0) {
				foundNegativeCycle = true;
				break;
			}
		}
		
		cout << (foundNegativeCycle ? "YES\n" : "NO\n");
	}

	return 0;
}