#include <bits/stdc++.h>
using namespace std;

int mxCost = 0;
int mxNode = -1;
bool vis[100005];
vector<pair<int, int>> adj[100005];

void dfs(int cur, int cost) {
	if (mxCost < cost) {
		mxCost = cost;
		mxNode = cur;
	}

	for (auto& [nxt, nxtCost] : adj[cur]) {
		if (vis[nxt]) continue;
		vis[nxt] = true;
		dfs(nxt, cost + nxtCost);
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int v; cin >> v;
	for (int i = 0; i < v; i++) {
		int a; cin >> a;
		while (true) {
			int b; cin >> b;
			if (b == -1) break;
			int c; cin >> c;
			adj[a].push_back({ b, c });
		}
	}

	vis[1] = true;
	dfs(1, 0);
	fill(vis, vis + v + 1, false);
	vis[mxNode] = true;
	dfs(mxNode, 0);
	cout << mxCost << '\n';

	return 0;
}