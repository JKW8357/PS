#include <bits/stdc++.h>
using namespace std;

set<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		s.insert(num);
	}

	int m; cin >> m;
	while (m--) {
		int num; cin >> num;
		cout << (s.count(num) ? 1 : 0) << '\n';
	}

	return 0;
}