#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		int cnt = 0;
		unordered_map<int, bool> um;

		while (n--) {
			int num;
			cin >> num;
			um[num] = true;
		}

		while (m--) {
			int num;
			cin >> num;
			if (um[num]) cnt++;
		}

		cout << cnt << '\n';
	}

	return 0;
}