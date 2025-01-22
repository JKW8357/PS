#include <bits/stdc++.h>
using namespace std;

struct tower {
	int x, y, r;
};

vector<int> p;
vector<tower> towers;

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) p[y] = x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		p.clear(); towers.clear();
		p.resize(n + 1); towers.resize(n + 1);
		for (int i = 1; i <= n; i++) p[i] = i;
		for (int i = 1; i <= n; i++) cin >> towers[i].x >> towers[i].y >> towers[i].r;

		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				int dx = towers[i].x - towers[j].x;
				int dy = towers[i].y - towers[j].y;
				int r_sum = towers[i].r + towers[j].r;
				if (dx * dx + dy * dy <= r_sum * r_sum) unite(i, j);
			}
		}

		for (int i = 1; i <= n; i++) find(i);
		set<int> s(p.begin() + 1, p.end());
		cout << s.size() << '\n';
	}

	return 0;
}