#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc; cin >> tc;
	while (tc--) {
		int l, n;
		cin >> l >> n;

		int mn = 0, mx = 0;
		while (n--) {
			int pos; cin >> pos;
			mn = max(mn, min(pos, l - pos));
			mx = max(mx, max(pos, l - pos));
		}

		cout << mn << ' ' << mx << '\n';
	}

	return 0;
}