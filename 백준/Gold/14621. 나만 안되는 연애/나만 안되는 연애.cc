#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> adj;
vector<int> p(1005, -1);
vector<char> sex(1005, ' ');

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

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> sex[i];
	for (int i = 1; i <= m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		adj.push_back({ d, u, v });
	}

	sort(adj.begin(), adj.end());

	int cnt = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		int u, v, d;
		tie(d, u, v) = adj[i];
		if (sex[u] == sex[v] || !unite(u, v)) continue;
		ans += d;
		cnt++;
		if (cnt == n - 1) break;
	}

	cout << (cnt == n - 1 ? ans : -1) << '\n';
	return 0;
}