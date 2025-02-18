#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> cost;
vector<bool> vis;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (cost[x] >= cost[y]) p[x] = y;
	else p[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	p.assign(n, -1);
	cost.resize(n);
	vis.assign(n, false);
	for (int i = 0; i < n; i++) cin >> cost[i];

	while (m--) {
		int v, w;
		cin >> v >> w;
		v--; w--;
		unite(v, w);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x = find(i);
		if (vis[x]) continue;
		vis[x] = true;
		ans += cost[x];
	}

	if (ans <= k) cout << ans << '\n';
	else cout << "Oh no\n";

	return 0;
}