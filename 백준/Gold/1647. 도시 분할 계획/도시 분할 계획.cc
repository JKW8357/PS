#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> adj[1000005];
vector<int> p(100005, -1);

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

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[i] = { c, a, b };
	}

	sort(adj, adj + m);

	int cnt = 0, sum = 0, max_edge = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		tie(c, a, b) = adj[i];
		if (!unite(a, b)) continue;
		sum += c;
		max_edge = max(max_edge, c);
		cnt++;
		if (cnt == n - 1) break;
	}

	int ans = sum - max_edge;
	cout << ans << '\n';
	return 0;
}