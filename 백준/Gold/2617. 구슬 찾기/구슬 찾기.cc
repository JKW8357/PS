#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (adj[i][k] == 1 && adj[k][j] == 1) adj[i][j] = 1;
				if (adj[i][k] == -1 && adj[k][j] == -1) adj[i][j] = -1;
			}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	adj.assign(n + 1, vector<int>(n + 1, 0));

	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = -1;
	}

	floyd();

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int heavy = 0, light = 0;
		for (int j = 1; j <= n; j++) {
			if (adj[i][j] == 1) heavy++;
			if (adj[i][j] == -1) light++;
		}
		if (heavy > n / 2 || light > n / 2) ans++;
	}

	cout << ans << '\n';
	return 0;
}