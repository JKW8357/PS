#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, ll>> adj[5005];
bool vis[5005];

ll dfs(int cur, ll cost) {
	vis[cur] = true;
	ll maxCost = cost;

	for (auto [nxt, nxtCost] : adj[cur]) {
		if (vis[nxt]) continue;
		maxCost = max(maxCost, dfs(nxt, cost + nxtCost));
	}

	return maxCost;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	ll ans = dfs(1, 0);
	cout << ans << '\n';

	return 0;
}