#include <bits/stdc++.h>
using namespace std;

bool check(int x, int y, int cx, int cy, int r) {
	int dx = cx - x;
	int dy = cy - y;
	return dx * dx + dy * dy <= r * r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc; cin >> tc;
	while (tc--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int n; cin >> n;

		int cnt = 0;
		while (n--) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			if (check(x1, y1, cx, cy, r) && !check(x2, y2,cx, cy, r)) cnt++;
			else if (!check(x1, y1, cx, cy, r) && check(x2, y2, cx, cy, r)) cnt++;
		}

		cout << cnt << '\n';
	}

	return 0;
}