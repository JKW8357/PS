#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<bool> vis(100005);
vector<int> apples(100005);
vector<int> adj[100005];

int dfs(int cur, int dist) {
	int result = apples[cur];
	if (dist == k) return result;

	for (int nxt : adj[cur]) {
		if (vis[nxt]) continue;
		vis[nxt] = true;
		result += dfs(nxt, dist + 1);
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int p, c;
		cin >> p >> c;
		adj[p].push_back(c);
		adj[c].push_back(p);
	}

	for (int i = 0; i < n; i++) cin >> apples[i];

	vis[0] = true;
	cout << dfs(0, 0) << '\n';
	return 0;
}