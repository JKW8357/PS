#include <bits/stdc++.h>
using namespace std;

unordered_map<string, priority_queue<int>> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long ans = 0;
	int q; cin >> q;
	while (q--) {
		int query; cin >> query;
		if (query == 1) {
			string name; cin >> name;
			int k; cin >> k;
			while (k--) {
				int c; cin >> c;
				m[name].push(c);
			}
		}


		else {
			string name; cin >> name;
			int b; cin >> b;
			while (!m[name].empty() && b--) {
				ans += m[name].top();
				m[name].pop();
			}
		}
	}

	cout << ans << '\n';
	return 0;
}