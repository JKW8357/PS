#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> maxright;
unordered_map<int, int> minleft;
set<pair<int, int>> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		s.insert({ l, r });

		maxright[l] = (maxright.count(l) ? max(maxright[l], r) : r);
		minleft[r] = (minleft.count(r) ? min(minleft[r], l) : l);
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;

		if (s.find({ l, r }) != s.end()) {
			cout << 1 << '\n';
			continue;
		}

		if (maxright.count(l) && maxright[l] > r && minleft.count(r) && minleft[r] < l) cout << 2 << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}