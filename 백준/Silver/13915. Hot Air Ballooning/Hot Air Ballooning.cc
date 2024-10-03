#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n) {
		int states[1005] = {};
		unordered_map<int, bool> um;

		for (int i = 0; i < n; i++) {
			int flights;
			cin >> flights;

			int tmp;
			while (flights != 0) {
				tmp = flights % 10;
				flights /= 10;
				states[i] |= (1 << tmp);
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!um[states[i]]) {
				um[states[i]] = true;
				cnt++;
			}
		}

		cout << cnt << '\n';
	}
	
	return 0;
}