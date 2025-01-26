#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> adj;
vector<int> p(1005, -1);

int find(int x) {
	if (p[x] == -1) return x;
	return p[x] = find(p[x]);
}

bool unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return false;
	p[y] = x;
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	int cnt = 0;
	while (k--) {
		int w; cin >> w;
		unite(w, n + 1);
		cnt++;
	}

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj.push_back({ w, u, v });
	}

	n++;
	sort(adj.begin(), adj.end());

	int ans = 0;
	for (auto& e : adj) {
		int u, v, d;
		tie(d, u, v) = e;
		if (!unite(u, v)) continue;
		ans += d;
		cnt++;
		if (cnt == n - 1) break;
	}

	cout << ans << '\n';
	return 0;
}