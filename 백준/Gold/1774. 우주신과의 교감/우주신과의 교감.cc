#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

vector<pair<int, int>> coord;
vector<tuple<ll, int, int>> adj;
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

	int n, m;
	cin >> n >> m;
	coord.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> coord[i].X >> coord[i].Y;
	
	int cnt = 0;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (unite(x, y)) cnt++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll dx = coord[j].X - coord[i].X;
			ll dy = coord[j].Y - coord[i].Y;
			ll dist = dx * dx + dy * dy;
			adj.push_back({ dist, i, j });
		}
	}

	sort(adj.begin(), adj.end());

	double ans = 0;
	for (auto& [dist, i, j] : adj) {
	    if (!unite(i, j)) continue;
	    ans += sqrt(dist);
	    cnt++;
	    if (cnt == n - 1) break;
	}

	cout << fixed << setprecision(2) << ans << '\n';
	return 0;
}