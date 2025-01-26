#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> adj;
vector<int> p(305, -1);

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

	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		int d; cin >> d;
		adj.push_back({ d, i, n + 1 });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int d; cin >> d;
			if (i == j) continue;
			adj.push_back({ d, i, j });
		}
	}

	n++;
	sort(adj.begin(), adj.end());

	int cnt = 0, ans = 0;
	for (int i = 0; i < (int)adj.size(); i++) {
		int u, v, d;
		tie(d, u, v) = adj[i];
		if (!unite(u, v)) continue;
		ans += d;
		cnt++;
		if (cnt == n - 1) break;
	}

	cout << ans << '\n';
	return 0;
}