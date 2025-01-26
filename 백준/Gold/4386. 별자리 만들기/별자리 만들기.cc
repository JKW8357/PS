#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<double, double>> coord;
vector<tuple<double, int, int>> adj;
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

	int n; cin >> n;
	coord.resize(n);
	for (int i = 0; i < n; i++) cin >> coord[i].X >> coord[i].Y;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dx = coord[j].X - coord[i].X;
			double dy = coord[j].Y - coord[i].Y;
			double dist = sqrt(dx * dx + dy * dy);
			adj.push_back({ dist, i, j });
		}
	}

	sort(adj.begin(), adj.end());

	int cnt = 0;
	double ans = 0;
	for (auto& e : adj) {
		double dist;
		int i, j;
		tie(dist, i, j) = e;
		if (!unite(i, j)) continue;
		ans += dist;
		cnt++;
		if (cnt == n - 1) break;
	}

	cout << fixed << setprecision(2) << ans << '\n';
	return 0;
}