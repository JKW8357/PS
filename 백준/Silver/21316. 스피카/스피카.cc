#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(13);
bool vis[13];

int dfs(int cur) {
	if (adj[cur].size() == 3) {
		int nxtEdgesCount = 0;
		for (int nxt : adj[cur]) nxtEdgesCount += (int)adj[nxt].size();
		if (nxtEdgesCount == 6) return cur;
	}

	for (int nxt : adj[cur]) {
		if (vis[nxt]) continue;
		vis[nxt] = true;
		int result = dfs(nxt);
		if (result != -1) return result;
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 12; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vis[1] = true;
	cout << dfs(1) << '\n';

	return 0;
}