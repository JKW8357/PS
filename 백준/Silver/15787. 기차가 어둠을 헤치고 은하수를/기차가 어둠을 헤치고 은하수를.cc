#include <bits/stdc++.h>
using namespace std;

int n, m;
int trains[100005];
unordered_map<int, bool> um;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	while (m--) {
		int cmd, i;
		cin >> cmd >> i;

		if (cmd == 1) {
			int x; cin >> x;
			trains[i] |= (1 << x);
		}

		else if (cmd == 2) {
			int x; cin >> x;
			trains[i] &= ~(1 << x);
		}

		else if (cmd == 3) {
			trains[i] <<= 1;
			trains[i] &= ~(1 << 21);
		}

		else {
			trains[i] >>= 1;
			trains[i] &= ~1;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!um[trains[i]]) {
			um[trains[i]] = true;
			cnt++;
		}
	}

	cout << cnt << '\n';
	return 0;
}