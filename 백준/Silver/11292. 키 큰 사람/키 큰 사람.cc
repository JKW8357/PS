#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int n; cin >> n;
		if (n == 0) break;

		map<double, vector<string>, greater<double>> m;
		while (n--) {
			string name; double height;
			cin >> name >> height;
			m[height].push_back(name);
		}

		for (auto& name : m.begin()->second) cout << name << ' ';
		cout << '\n';
	}

	return 0;
}