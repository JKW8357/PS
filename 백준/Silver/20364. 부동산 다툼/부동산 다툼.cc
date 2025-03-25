#include <bits/stdc++.h>
using namespace std;

bool vis[1050000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q;
	cin >> n >> q;

	while (q--) {
		int x; cin >> x;
		int cur = x;
		int firstVisited = x;
		bool canVisit = true;

		while (cur > 0) {
			if (vis[cur]) {
				canVisit = false;
				firstVisited = cur;
			}
			cur /= 2;
		}

		if (canVisit) vis[x] = true;
		cout << (canVisit ? 0 : firstVisited) << '\n';
	}

	return 0;
}